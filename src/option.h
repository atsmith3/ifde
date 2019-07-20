#ifndef UTILITY_OPTION_H_
#define UTILITY_OPTION_H_

#include <iostream>
#include <string>

namespace Utility {
  class Options {
    public:
      std::string sequence;
      std::string intermediate;
      std::string output;
      int threshold;
      int images;

      Options();
      ~Options();
      bool parse(int argc, char** argv);
  }; //End of class Options
}; //End of namespace Utility

#endif
