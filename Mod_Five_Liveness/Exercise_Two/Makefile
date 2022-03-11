# Abandoned Lock Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++17
TARGET	 = abandoned_lock
SRC		 = abandoned_lock.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
