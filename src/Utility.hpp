#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include <vector>

class Utility {

  public:

    // Construction
    Utility(size_t _size) {
      m_array = std::vector<int>(_size);
      m_pointer = &m_array[0];
    }

    // Destruction
    ~Utility() {}

    // Compile a given program string
    std::string Compile(std::string _program);

    // Getters and setters
    std::vector<int>& GetArray() { return m_array; }

    int* GetPointer() { return m_pointer; }

  private:

    // Main array that stores the program's values
    std::vector<int> m_array;

    int* m_pointer;
};

#endif
