#include <iostream>
#include "option.h"

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

  return 1;
}
