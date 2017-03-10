#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include "Utility.hpp"

class Interpreter {

  public:

    Interpreter() {}

    Interpreter(size_t _size);

    ~Interpreter() {}

    // Initialize interpreter and continuously take input.
    void Interpret();

  private:

    // Stores the main array and data pointer.
    Utility m_utility;

    // If set to false, then the array wont be reset on each input line givne to
    // the interpreter. Essentially, the 'array' will be persistent until the
    // interpreter is quit.
    bool m_reset{true};
};

#endif
