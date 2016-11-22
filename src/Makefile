CXX = g++
CPPFLAGS = -std=c++11 -Werror -Wall -g

SRCS = main.cpp Interpreter.cpp Utility.cpp

OBJS = $(SRCS:.cpp=.o)

bfc: main.cpp Interpreter.cpp Utility.cpp
	$(CXX) $(CPPFLAGS) $(SRCS) -o $@

depend: .depend

.depend: $(SRCS)
	rm -rf ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	rm *.o bfc
