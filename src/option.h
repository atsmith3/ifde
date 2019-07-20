#ifndef MAESTRO_OPTION_H_
#define MAESTRO_OPTION_H_

#include <iostream>
#include <string>

namespace Utility {
  class Options {
    public:
      std::string input_filelist;
      std::string intermediate_dir;
      std::string output_file;
      int threshold;

      Options();
      ~Options();
      bool parse(int argc, char** argv);
  }; //End of class Options
}; //End of namespace Utility

#endif
