#ifndef INAGE_CONVOLUTION_H_
#define IMAGE_CONVOLUTION_H_

#include "png.h"

namespace Image {

  void convolve(PNG& input, PNG& output);
  
	void threshold(PNG& input, PNG& output, int threshold);

}

#endif

