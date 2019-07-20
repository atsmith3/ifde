
#include "rgbapixel.h"


namespace Image {

  void convolve(PNG& input, PNG& output) {
    // Edge Detection:
    int edgeDetection[9] = {-2,-2,-2,-2,16,-2,-2,-2,-2};
    
    int red = 0;
    int blue = 0;
    int green = 0;

    uint8_t average = 0;

    for(int x = 0; x < input.width(); x++) {
      for(int y = 0; y < input.height(); y++) {
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
    }
  }
  
  void threshold(PNG& input, PNG& output, int threshold) {
    // TODO: Remove pixels that are below the threshold
    return output;
  }
}
