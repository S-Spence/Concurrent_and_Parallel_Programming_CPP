# Thread vs. Process Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = thread_vs_process
SRC		 = thread_vs_process.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
