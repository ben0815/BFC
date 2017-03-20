#include "Utility.hpp"


Utility::
Utility(size_t _size) {
  m_size = _size;
  m_array = std::vector<int>(m_size, 0);
  m_pointer = m_array.begin();
}


void
Utility::
Compile(std::string _program) {
  // Start timing clock.
  auto t1 = std::chrono::high_resolution_clock::now();

  // Loop through program and switch for the possible commands.
  for(auto cit = _program.begin(); cit != _program.end(); ++cit) {
    if(*cit == '+')
      ++*m_pointer;
    else if(*cit == '-')
      --*m_pointer;
    else if(*cit == '>' ) {
      if(m_pointer == m_array.end()) {
        std::cerr << "Cannot increment pointer past end of array." << std::endl;

        return;
      }
      else
        ++m_pointer;
    }
    else if(*cit == '<') {
      if(m_pointer == m_array.begin()) {
        std::cerr << "Cannot decrement pointer before beginning of array."
          << std::endl;

          return;
      }
      else
        --m_pointer;
    }
    else if(*cit == '.') {
      std::cout << static_cast<char>(*m_pointer);
    }
    else if(*cit == ',') {
      std::cout << "Input: ";
      std::cin >> *m_pointer;
    }
    
    else if(*cit == '[') {
      if(*m_pointer == 0) {
        size_t count = 1;

        while(count > 0) {
          if(cit == _program.cend()) {
            std::cerr << "Missing \']\'." << std::endl;

            return;
          }

          ++cit;

          if(*cit == '[')
            ++count;
          else if(*cit == ']')
            --count;
        }
      }
    }
    else if(*cit == ']') {
      if(*m_pointer != 0) {
        size_t count = 1;

        while(count > 0) {
          if(cit == _program.cbegin()) {
            std::cerr << "Missing \'[\'." << std::endl;

            return;
          }

          --cit;

          if(*cit == '[')
            --count;
          else if(*cit == ']')
            ++count;
        }
      }
    }
  }
  std::cout << std::endl;

  // Compute and output timing.
  auto t2 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = std::chrono::duration_cast<
    std::chrono::duration<double>>(t2 - t1);

  std::ofstream ofs("../Testing/times.txt", std::ios::app);

  if(!_program.empty()) {
    ofs << "Program: " << _program << std::endl;
    ofs << "Compile time: " << elapsed.count() << " seconds." << std::endl;
    ofs << std::endl << std::endl;
  }
}


void
Utility::
Reset() {
  // Re initialize the array to 0.
  m_array = std::vector<int>(m_size, 0);
  m_pointer = m_array.begin();
}
