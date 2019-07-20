#include "option.h"
#include <boost/program_options.hpp>

namespace Utility {
  namespace po = boost::program_options;

  Options::Options() {
    std::string original = "";
    std::string sequence = "";
    std::string intermediate = "";
    std::string output = "";
    int threshold = 0;
    int images = 0;
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
      ("original", po::value<std::string>(&original), "path to original color image")
      ("sequence", po::value<std::string>(&sequence), "path to folder to the input sequence")
      ("intermediate", po::value<std::string>(&intermediate), "path to folder to store intermediate output")
      ("output", po::value<std::string>(&output), "output file name")
    ;

    po::options_description conv_opt("Convolution Options");
    conv_opt.add_options()
      ("threshold", po::value<int>(&threshold), "threshold to accept a pixel")
      ("images", po::value<int>(&images), "number of images in the sequence")
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
