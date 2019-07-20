#include <iostream>
#include "option.h"
#include "depth.h"
#include "kernel.h"
#include "convolution.h"
#include "png.h"
#include <vector>

int main(int argc, char** argv) {
Utility::Options opt;

  opt.parse(argc, argv);

  std::cout << "Unit Tests\n";
  std::cout << "-------------------------------------------\n";
  std::cout << "\n";

//  std::cout << "Arguments\n";
//  std::cout << "-------------------------------------------\n";
//  std::cout << "\n";
//
//  std::cout << "Depth\n";
//  std::cout << "-------------------------------------------\n";
//  Utility::PixelDepth data(4,5,6);
//  data.set_depth(1,2,3);
//  //data.write_debug("unit_test.csv");
//  std::cout << "\n";
//
//  std::cout << "Kernel\n";
//  std::cout << "-------------------------------------------\n";
//  std::cout << "Testing default kernel\n";
//  Kernel test1;
//  for(int i = 0; i < test1.getSize(); i++)
//  {
//      std::cout << test1[i] << " ";
//  }
//  
//  std::cout << "\nTesting kernel constructor\n";
//  std::vector<int> test2vector = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
//  Kernel test2(test2vector);
//  for(int i = 0; i < test2.getSize(); i++)
//  {
//      std::cout << test2[i] << " ";
//  }
//  
//  std::cout << "\nTesting only vectors with perfect sqaures are used\n";
//  test2vector.pop_back();
//  Kernel test3(test2vector);
//  
//  std::cout << "\nTesting = operator\n";
//  Kernel test4 = test2;
//  for(int i = 0; i < test4.getSize(); i++)
//  {
//      std::cout << test4[i] << " ";
//  }
//  
//  test4 = test1;
//  std::cout << "\n";
//  for(int i = 0; i < test4.getSize(); i++)
//  {
//      std::cout << test4[i] << " ";
//  }
//  
//  test4 = test3;
//  for(int i = 0; i < test4.getSize(); i++)
//  {
//      std::cout << test4[i] << " ";
//  }

  std::cout << "Convolution\n";
  std::cout << "-------------------------------------------\n";
  PNG* original = new PNG("test/original.png");
  PNG* input = new PNG("test/input.png");
  PNG* conv = new PNG(*input);
  PNG* thresh = new PNG(*input);
  Utility::PixelDepth* data = new Utility::PixelDepth(original->width(), original->height(), 1);
  Image::convolve(*input, *conv);
  Image::threshold(*conv, *thresh, 50);
  Image::add(*thresh, *data, 1);
  conv->writeToFile("test/conv.png");
  thresh->writeToFile("test/thresh.png");
  data->write_output("test/out.csv", *original);
  std::cout << "\n";

  return 1;
}
