# Recursive Mutex Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = recursive_mutex
SRC		 = recursive_mutex.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
