default: all

all:
	g++ -o exec/simexec src/main.cpp -std=c++11

bbb:
	g++ -std=c++11 -o exec/bbbexec src/estado/bigbrother.hpp -fpermissive
