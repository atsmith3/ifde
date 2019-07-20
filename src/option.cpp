#include "option.h"
#include <boost/program_options.hpp>

namespace Utility {
  namespace po = boost::program_options;

  Options::Options() {
    std::string input_filelist = "";
    std::string intermediate_dir = "";
    std::string output_file = "";
    int threshold = 0;
  }

  Options::~Options() {
    // Do Nothing
  }

  bool Options::parse(int argc, char** argv) {
    po::options_description desc("General Options");
    desc.add_options()
        ("help", "Display help message")
    ;

    po::options_description io_opt("File IO options");
    io_opt.add_options()
      ("file_list", po::value<std::string>(&input_filelist), "path to list of input files")
      ("intermediate_dir", po::value<std::string>(&intermediate_dir), "path to folder to store intermediate output")
      ("output_file", po::value<std::string>(&output_file), "path to folder to store intermediate output")
    ;

    po::options_description conv_opt("Convolution Options");
    conv_opt.add_options()
      ("threshold", po::value<int>(&threshold), "threshold to accept a pixel")
    ;

    po::options_description all_options;
    all_options.add(desc);
    all_options.add(io_opt);
    all_options.add(conv_opt);

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, all_options), vm);
    po::notify(vm);

    return true;
  }
}; //End of namespace Utility
