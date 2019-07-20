#include "depth.h"
#include <fstream>

namespace Utility {

  PixelDepth::PixelDepth(int width, int height, int depth) {
    data.resize(width);
    for(size_t x = 0; x < data.size(); x++) {
      data[x].resize(height);
      for(size_t y = 0; y < data[x].size(); y++) {
        data[x][y].resize(depth);
        for(size_t z = 0; z < data[x][y].size(); z++) {
          data[x][y][z] = 0;
        }
      }
    }
  }

  PixelDepth::~PixelDepth() {
    // Do Nothing
  }
  
  void PixelDepth::set_depth(int x, int y, int z) {
    data[x][y][z] = 1;
  }

  void PixelDepth::write_debug(std::string fname) {
    std::ofstream csv;
    csv.open(fname);
    for(size_t x = 0; x < data.size(); x++) {
      for(size_t y = 0; y < data[x].size(); y++) {
        csv << x << "," << y << ",";
        for(size_t z = 0; z < data[x][y].size(); z++) {
          csv << data[x][y][z] << ",";
        }
        csv << "\n";
      }
    }
    csv.close();
  }

  void PixelDepth::write_output(std::string fname, PNG& original) {
    std::ofstream csv;
    csv.open(fname);
    int sum, total, depth;
    for(size_t x = 0; x < data.size(); x++) {
      for(size_t y = 0; y < data[x].size(); y++) {
        sum = 0;
        total = 0;
        csv << x << "," << y << ",";
        for(size_t z = 0; z < data[x][y].size(); z++) {
          if(data[x][y][z] == 1) {
            sum += z;
            total++;
          }
        }
        if(total == 0) {
          depth = -1;
        }
        else {
          depth = sum/total;
        }
        csv << depth << ",";
        csv << original(x,y)->red << ",";
        csv << original(x,y)->green << ",";
        csv << original(x,y)->blue << ",";
        csv << "\n";
      }
    }
    csv.close();
  }

} // namespace Utility
