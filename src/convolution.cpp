#include "convolution.h"
#include "rgbapixel.h"
#include "kernel.h"

namespace Image {

  void convolve(PNG& input, PNG& output) {
    Kernel edgeDetection;
    

    uint8_t average = 0;

    for(size_t x = 0; x < input.width(); x++) {
      for(size_t y = 0; y < input.height(); y++) {
        int red = 0;
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
              red   += edgeDetection[j*3 + i]*(int)input(x - 1 + i, y - 1 + j)->red;
            }
          }

          if(red > 255) {
            average = 255;
          }
          else if (red < 0) {
            average = 0;
          }
          else {
            average = (size_t)(red);
          }

          //std::cout << x << " " << y << " " << (int)average << " " << red << "\n";
          
          output(x,y)->red = average;
          output(x,y)->green = average;
          output(x,y)->blue = average;
        }
      }
    }
  }
  
  void threshold(PNG& input, PNG& output, int threshold) {
    for(size_t i = 0; i < input.width(); i++) {
      for(size_t j = 0; j < input.height(); j++) {
        if(input(i,j)->red > threshold) {
          output(i,j)->red = 255;
          output(i,j)->green = 255;
          output(i,j)->blue = 255;
        }
        else {
          output(i,j)->red = 0;
          output(i,j)->green = 0;
          output(i,j)->blue = 0;
        }
      }
    }
    return;
  }
	
  void add(PNG& input, Utility::PixelDepth& data, int depth) {
    for(size_t i = 0; i < input.width(); i++) {
      for(size_t j = 0; j < input.height(); j++) {
        if(input(i,j)->red > 0) data.set_depth(i, j, depth);
      }
    }
    return;
  }

}
