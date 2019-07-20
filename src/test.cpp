#include <iostream>
#include "option.h"
#include "kernel.h"

#include <vector>
int main(int argc, char** argv) {
Utility::Options opt;

  opt.parse(argc, argv);

  std::cout << "Unit Tests\n";
  std::cout << "-------------------------------------------\n";
  std::cout << "\n";

  std::cout << "Arguments\n";
  std::cout << "-------------------------------------------\n";
  std::cout << "input_filelist: " << opt.input_filelist << "\n";
  std::cout << "intermediate_dir: " << opt.intermediate_dir << "\n";
  std::cout << "output_file: " << opt.output_file << "\n";
  std::cout << "threshold: " << opt.threshold << "\n";

    std::cout << "Kernel\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Testing default kernel\n";
    Kernel test1;
    for(int i = 0; i < test1.getSize(); i++)
    {
        std::cout << test1[i] << " ";
    }
    
    std::cout << "\nTesting kernel constructor\n";
    std::vector<int> test2vector = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    Kernel test2(test2vector);
    for(int i = 0; i < test2.getSize(); i++)
    {
        std::cout << test2[i] << " ";
    }
    
    std::cout << "\nTesting only vectors with perfect sqaures are used\n";
    test2vector.pop_back();
    Kernel test3(test2vector);
    
    std::cout << "\nTesting = operator\n";
    Kernel test4 = test2;
    for(int i = 0; i < test4.getSize(); i++)
    {
        std::cout << test4[i] << " ";
    }
    
    test4 = test1;
    std::cout << "\n";
    for(int i = 0; i < test4.getSize(); i++)
    {
        std::cout << test4[i] << " ";
    }
    
    test4 = test3;
    for(int i = 0; i < test4.getSize(); i++)
    {
        std::cout << test4[i] << " ";
    }
    
    
    
  return 1;
}
