all: ./src/main.cpp
	g++ ./src/main.cpp -std=c++11 -O2 -o puzzle
clean:
	rm -f puzzle