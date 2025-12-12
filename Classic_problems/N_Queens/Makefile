
FILE ?= main
SRC := $(FILE).cpp
TARGET := ./output/$(basename $(SRC))
CXX= g++
CXXFLAGS = -Wall -g

all: $(TARGET)

output:
	mkdir -p ./output

$(TARGET): $(SRC) chessboard.cpp | output
	$(CXX) $(CXXFLAGS) -o $@ $(SRC) chessboard.cpp
	

run: $(TARGET)
	./$(TARGET)

./output/%: %.cpp chessboard.cpp | output
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f ./output/$(basename $(SRC)) *.o
	rmdir ./output 2>/dev/null || true

.PHONY: all run clean output
 
