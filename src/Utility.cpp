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
  for(auto cit = _program.cbegin(); cit != _program.cend(); ++cit) {
    if(*cit == '+')
      ++*m_pointer;
    else if(*cit == '-')
      --*m_pointer;
    else if(*cit == '>' ) {
      if(m_pointer == m_array.end())
        std::cerr << "Cannot increment pointer past end of array." << std::endl;
      else
        ++m_pointer;
    }
    else if(*cit == '<') {
      if(m_pointer == m_array.begin())
        std::cerr << "Cannot decrement pointer before beginning of array."
          << std::endl;
      else
        --m_pointer;
    }
    else if(*cit == '.') {
      if(*m_pointer < 32)
        std::cout << *m_pointer;
      else
        std::cout << static_cast<char>(*m_pointer);

      std::cout << " ";
    }
    else if(*cit == ',') {
      std::cout << "Input: ";
      std::cin >> *m_pointer;
    }
    // TODO: Currently doesn't handle nested loops
    else if(*cit == '[') {
      std::cout << "left";
      if(*m_pointer == 0)
        std::cout << "yes";
        while(*cit != ']') {
          if(cit == _program.cend()) {
            std::cerr << "Missing \']\'." << std::endl;

            return;
          }

          ++cit;
          //std::cout << *cit;
        }

      ++cit;
    }
    else if(*cit == ']') {
    std::cout << "what22";
      if(*m_pointer != 0)
        while(*cit != '[')
          --cit;

      --cit;
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
