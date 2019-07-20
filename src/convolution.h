#ifndef IMAGE_CONVOLUTION_H_
#define IMAGE_CONVOLUTION_H_

#include "png.h"
#include "depth.h"

namespace Image {

  void convolve(PNG& input, PNG& output);
  
	void threshold(PNG& input, PNG& output, int threshold);

	void add(PNG& input, Utility::PixelDepth& data, int depth);

}

#endif

