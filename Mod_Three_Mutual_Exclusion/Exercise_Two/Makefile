# Mutual exclusion Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = mutual_exclusion
SRC		 = mutual_exclusion.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
