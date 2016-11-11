CXX = g++ -std=c++11
CPPFLAGS = -Werror

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

bfc:
	$(CXX) $(CPPFLAGS) $(SRCS) -o $@

depend: .depend

.depend: $(SRCS)
	rm -rf ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	rm *.o bfc
