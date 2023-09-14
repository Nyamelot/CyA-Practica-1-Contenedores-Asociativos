
#include <string>
#include <iostream>

const std::string kTitle = "p01-containers";
const std::string kHelpText;

void Usage(int argc, char* argv[]) {
  const std::string kHelp = "--help";
  if (argc == 1) {
    std::cerr << argv[0] << std::endl << kTitle << std::endl;
    std::cerr << "Forma de uso: " << kHelpText;
    exit(EXIT_FAILURE);
  }
}