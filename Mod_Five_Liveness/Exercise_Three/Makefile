# Starvation Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = starvation
SRC		 = starvation.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
