#include "Interpreter.hpp"

Interpreter::
Interpreter(size_t _size) {
  m_utility = Utility(_size);
}


void
Interpreter::
Interpret() {
  // Continuously read from standard input and compile/run each line.
  for(;;) {
    std::cout << "> ";

    std::string program = "";

    std::getline(std::cin, program);

    if(program == "quit" || program == "exit" || program == "q") {
      std::cout << "Leaving interpreter mode." << std::endl;

      return;
    }

    m_utility.Compile(program);

    // If reset mode is on reset the array after each input line.
    if(m_reset)
      m_utility.Reset();
  }

  return;
}
