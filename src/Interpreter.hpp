#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <memory>

#include "Utility.hpp"

class Interpreter {

  public:

    // Construction
    Interpreter(size_t _size);

    // Destruction
    ~Interpreter() {}

    // Initialize interpreter and continuously take input
    void Interpret();

  private:

    // Pointer to the Utility
    // This stores the main array and data pointer
    std::shared_ptr<Utility> m_utility;
};

#endif
