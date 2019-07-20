// Andrew Smith
//
// Image manipulation with single thread vs multiple threads
//
// 1/8/16

#include <iostream>
#include <string>
#include <stdio.h>
#include "png.h"
#include <pthread.h>
#include <math.h>
#include <chrono>

#define NUMBER_OF_THREADS 64

typedef struct _chunk_args {
    PNG* input;
    PNG* output;
    size_t start_x;
    size_t start_y;
    size_t chunk_width;
    size_t chunk_height;
} chunk_args;

void convolve(PNG& input, PNG& output, size_t x, size_t y) {
    // Edge Detection:
    int edgeDetection[9] = {-2,-2,-2,-2,16,-2,-2,-2,-2};
    
    int red = 0;
    int blue = 0;
    int green = 0;

    uint8_t average = 0;

    // Ignore outer row of pixels:
    if(x == 0 || y == 0 || x == input.width() - 1 || y == input.height() - 1) {
        // Set pixels to black:
        output(x,y)->red = 0;
        output(x,y)->green = 0;
        output(x,y)->blue = 0;
    }
    else {
        for(uint8_t i = 0; i < 3; i++) {
            for(uint8_t j = 0; j < 3; j++) {
                red   += edgeDetection[j*3 + i]*input(x - 1 + i, y - 1 + j)->red;
                green += edgeDetection[j*3 + i]*input(x - 1 + i, y - 1 + j)->green;
                blue  += edgeDetection[j*3 + i]*input(x - 1 + i, y - 1 + j)->blue;
            }
        }

        if((red + green + blue)/3 > 150) {
            average = 255;
        }
        else if((red + green + blue)/3 < 0) {
            average = 0;
        }
        else {
            average = (size_t)((red + green + blue)/3);
        }
        
        output(x,y)->red = average;
        output(x,y)->green = average;
        output(x,y)->blue = average;
    }
}

void* convolveChunk(void* arguments) {
    // Convolve over a chunk of the image:
    chunk_args* cargs = (chunk_args *)arguments;
    for(size_t i = 0; i < cargs->chunk_width; i++) {
        for(size_t j = 0; j < cargs->chunk_height; j++) {
            convolve(*cargs->input, *cargs->output, cargs->start_x + i, cargs->start_y + j);
        }
    }   
    return NULL;
}

bool convolveParallel(PNG& input, PNG& output) {
    // Determine the image chunks the threads will process:
    chunk_args cargs[NUMBER_OF_THREADS];

    for(size_t i = 0; i < NUMBER_OF_THREADS; i++) {
        cargs[i].chunk_width = input.width()/sqrt(NUMBER_OF_THREADS);
        cargs[i].chunk_height = input.height()/sqrt(NUMBER_OF_THREADS);    
        cargs[i].start_x = 0;
        cargs[i].start_y = 0;

        cargs[i].input = &input;
        cargs[i].output = &output;
    }

    pthread_t threads[NUMBER_OF_THREADS];
     
    // Begin convolution on the image subsets:
    for(size_t i = 0; i < sqrt(NUMBER_OF_THREADS); i++) {
        for(size_t j = 0; j < sqrt(NUMBER_OF_THREADS); j++) {
            cargs[j*(int)sqrt(NUMBER_OF_THREADS) + i].start_x = cargs[j*(int)sqrt(NUMBER_OF_THREADS) + i].chunk_width * i;
            cargs[j*(int)sqrt(NUMBER_OF_THREADS) + i].start_y = cargs[j*(int)sqrt(NUMBER_OF_THREADS) + i].chunk_height * j;

            if(pthread_create(&threads[j*(int)sqrt(NUMBER_OF_THREADS) + i], NULL, convolveChunk, (void *)&cargs[j*(int)sqrt(NUMBER_OF_THREADS) + i])){
                std::cout << "Error Creating Thread: " << i << "\n";
                return false;
            }
        }       
    }
    
    for(size_t i = 0; i < NUMBER_OF_THREADS; i++) {
        if(pthread_join(threads[i], NULL)) {
            std::cout << "Error Joining Thread: " << i << "\n";
            return false;
        }
    }
    
    return true;
}

bool convolveSerial(PNG& input, PNG& output) {
    // Begin convolution over the whole Image:
    for(size_t i = 0; i < input.width(); i++) {
        for(size_t j = 0; j < input.height(); j++) {
            convolve(input, output, i, j);
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Timer Vars:
    std::chrono::high_resolution_clock::time_point t0, t1;

    // Get the input PNG:
    PNG* input = new PNG;
    PNG* output = new PNG;
    
    input->readFromFile("in.png");
    output->resize(input->width(), input->height());
    
    // Start the timer:
    t0 = std::chrono::high_resolution_clock::now();
    
    if(convolveSerial(*input, *output) == true) {
        std::cout << "First Pass Complete\n";
    }

    // End the timer:
    t1 = std::chrono::high_resolution_clock::now();

    // Print the duration:
    auto real_runtime = std::chrono::duration<double, typename std::chrono::high_resolution_clock::period>(t1 - t0);
    std::cout << "The convolution runtime is " << (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(real_runtime).count()/1000000000.0) << " seconds\n";

    // Write the png to the file:
    output->writeToFile("output.png");
    
    // Free Memory:
    delete input;
    delete output;
    
    return 0;
} 
