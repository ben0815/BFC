#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Interpreter.hpp"
#include "Compiler.hpp"

int
main(int argc, char** argv) {
  int c = 0;

  // Default array size
  size_t size = 30000;

  char* executable = nullptr;
  char* filename = nullptr;

  // If there is more than one argument then we will compile
  if(argc > 1) {
    // Get command line arguments
    while ((c = getopt(argc, argv, "f:o:s:")) != -1) {
      switch (c) {
        case 'o':
          executable = optarg;
          break;
        case 'f':
          filename = optarg;
          break;
        case 's':
          size = atol(optarg);
          break;
        default:
          std::cerr << "Incorrect usage." << std::endl;

          // Make sure a file was provided to compile
          if(!filename)
            std::cerr << "Filename must be provided with -f." << std::endl;

          std::cerr << "Usage:  ./bfc -f filename.b -o executablename" << std::endl;
          return -1;
      }
    }

    // Convert the filename to a string and check its extension
    std::string file(filename);
    if(file.substr(strlen(filename) - 2, 2) != ".b") {
      std::cerr << "This is a BF compiler, files must have the '.b' extension."
        << std::endl;

      return -1;
    }

    // TODO: Compile the given file

    std::cout << "Compiling " << file << "..." << std::endl;

  }
  //If there are no arguments go into interpreter mode
  else {
    std::cout << "Entering interpreter mode..." << std::endl;

    Interpreter interpreter(size);

    interpreter.Interpret();
  }

  return 0;
}
