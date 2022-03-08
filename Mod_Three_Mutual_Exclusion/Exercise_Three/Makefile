# Atomic Objects Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = atomic_objects
SRC		 = atomic_objects.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
