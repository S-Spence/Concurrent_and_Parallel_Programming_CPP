# Data race Makefile
CXX		 = g++
CXXFLAGS = -Wall -std=c++11
TARGET	 = data_race
SRC		 = data_race.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET)
