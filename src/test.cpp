#include <iostream>
#include "option.h"
#include "depth.h"

int main(int argc, char** argv) {
  Utility::Options opt;

  opt.parse(argc, argv);

  std::cout << "Unit Tests\n";
  std::cout << "-------------------------------------------\n";
  std::cout << "\n";

  std::cout << "Arguments\n";
  std::cout << "-------------------------------------------\n";
  std::cout << "\n";

  std::cout << "Depth\n";
  std::cout << "-------------------------------------------\n";
  Utility::PixelDepth data(4,5,6);
  data.set_depth(1,2,3);
  data.write_debug("unit_test.csv");
  std::cout << "\n";

  return 1;
}
