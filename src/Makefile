CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -Werror -std=c++11 -pedantic -funsafe-math-optimizations -msse4 -mavx

all: registers.o

registers: registers.o
	$(CXX) $(CXXFLAGS) -o $@ $<

registers.o: registers.hpp select.hpp registers-private.hpp
	$(CXX) $(CXXFLAGS) -c registers.hpp

clean:
	rm -f *.o

