# Try Lock Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = try_lock
SRC		 = try_lock.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
