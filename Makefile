all:
	g++ main.cpp FastCircle.h FastHelix.h FastLine.h GlobalPoint.h -std=c++11 -o main -g -O0

clean:
	rm -rf main

