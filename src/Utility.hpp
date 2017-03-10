#ifndef UTILITY_HPP_
#define UTILITY_HPP_

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>

typedef std::vector<int>::iterator VIT;

class Utility {

  public:

    Utility() {}

    Utility(size_t _size);

    ~Utility() {}

    // Compile a given program string.
    void Compile(std::string _program);

    void Reset();

  private:

    size_t m_size{30000};

    // Main array that stores the program's values.
    std::vector<int> m_array;

    // Pointer which moves along the array.
    VIT m_pointer{m_array.begin()};
};

#endif
