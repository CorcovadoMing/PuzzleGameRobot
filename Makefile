all: ./src/Puzzle.cpp
	g++ ./src/Puzzle.cpp -std=c++11 -O2 -o puzzle
clean:
	rm -f puzzle