// Andrew Smith
// Image manipulation with single thread vs multiple threads
// 1/8/16

#include <iostream>
#include <string>
//#include "png.h"
#include "option.h"
#include <chrono>

int main(int argc, char** argv) {
  // Parse Arguments:
  Utility::Options opt;
  opt.parse(argc, argv);

  // Timer Vars:
  std::chrono::high_resolution_clock::time_point t0, t1;

  // Get the input PNG:
//  PNG* input = new PNG;
//  PNG* conv_result = new PNG;
//  PNG* thresh_result = new PNG;

  // Main Loop
  for(int image_num = 0; image_num < opt.images; image_num++) {
    char buff[100];
    snprintf(buff, sizeof(buff), "%03d.png", image_num);
    std::string file_name = buff;
    std::cout << file_name + "\n";
//    input->readFromFile(opt.sequence + "/" + );
//    output->resize(input->width(), input->height());
//    
//    // Start the timer:
//    t0 = std::chrono::high_resolution_clock::now();
//    
//    if(convolveSerial(*input, *output) == true) {
//        std::cout << "First Pass Complete\n";
//    }
//
//    // End the timer:
//    t1 = std::chrono::high_resolution_clock::now();
//
//    // Print the duration:
//    auto real_runtime = std::chrono::duration<double, typename std::chrono::high_resolution_clock::period>(t1 - t0);
//    std::cout << "The convolution runtime is " << (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(real_runtime).count()/1000000000.0) << " seconds\n";
//
//    // Write the png to the file:
//    output->writeToFile("output.png");
  }
  
  // Free Memory:
//  delete input;
//  delete output;
  
  return 0;
} 
