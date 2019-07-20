// Andrew Smith
// Image manipulation with single thread vs multiple threads
// 1/8/16

#include <iostream>
#include <string>
#include "png.h"
#include "option.h"
#include "depth.h"
#include "convolution.h"
#include <chrono>

int main(int argc, char** argv) {
  // Parse Arguments:
  Utility::Options opt;
  opt.parse(argc, argv);
  
  char buff[100];

  // Timer Vars:
  std::chrono::high_resolution_clock::time_point t0, t1;

  // Get the input PNG:
  PNG* original = new PNG(opt.original);
  Utility::PixelDepth* data = new Utility::PixelDepth(original->width(), original->height(), opt.images);

  // Main Loop
  for(int image_num = 1; image_num <= opt.images; image_num++) {
    // Start the timer:
    t0 = std::chrono::high_resolution_clock::now();
    snprintf(buff, sizeof(buff), "%03d.png", image_num);
    std::string file_name = buff;

    // Load the new Image
    PNG* input = new PNG(opt.sequence + "/" + file_name);
    PNG* conv = new PNG(input->width(), input->height());
    PNG* thresh = new PNG(input->width(), input->height());

    // Run the Core
    Image::convolve(*input, *conv);
    Image::threshold(*conv, *thresh, opt.threshold);
    Image::add(*thresh, *data, image_num);

    // Write the Intermediate Files
    conv->writeToFile(opt.intermediate + "/conv" + file_name);
    thresh->writeToFile(opt.intermediate + "/thresh" + file_name);

    // Free Images
    delete input;
    delete conv;
    delete thresh;

    // End the timer:
    t1 = std::chrono::high_resolution_clock::now();
    auto real_runtime = std::chrono::duration<double, typename std::chrono::high_resolution_clock::period>(t1 - t0);
    std::cout << file_name + " time: " << (double)(std::chrono::duration_cast<std::chrono::nanoseconds>(real_runtime).count()/1000000000.0) << " seconds\n";
  }
  
  data->write_output(opt.output, *original);

  // Free Memory:
  delete original;
  
  return 0;
} 
