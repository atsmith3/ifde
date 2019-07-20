#ifndef UTILITY_DEPTH_H_
#define UTILITY_DEPTH_H_

#include <vector>
#include <iostream>
#include <string>
#include "png.h"

namespace Utility {

  class PixelDepth {
    private:
      std::vector<std::vector<std::vector<int>>> data;

    public:
      PixelDepth(int width, int height, int depth);
      ~PixelDepth();
      
      void set_depth(int x, int y, int z);

      void write_debug(std::string fname);
      void write_output(std::string fname, PNG& original);
  };

}

#endif
