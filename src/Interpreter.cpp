#include "Interpreter.hpp"

Interpreter::
Interpreter(size_t _size) {
  // Initialize utility
  m_utility = std::make_shared<Utility>(Utility(_size));
}


void
Interpreter::
Interpret() {
  // TODO:
  //       Continuously read from standard input
  //       Perform operation depending on command
  //       Prompt for input if necessary
  //       Send output if necessary
  //       Do not crash if bad input is given

  for(;;) {
    std::cout << "> ";

    std::string program = "";

    std::getline(std::cin, program);

    if(program == "quit" || program == "exit" || program == "q") {
      std::cout << "Leaving interpreter mode." << std::endl;

      return;
    }

    std::string output = m_utility->Compile(program);

    std::cout << output << std::endl;
  }

  return;
}
