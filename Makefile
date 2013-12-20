all: ./src/Puzzle.cpp
	g++ ./src/Puzzle.cpp -o puzzle
clean:
	rm -f puzzle