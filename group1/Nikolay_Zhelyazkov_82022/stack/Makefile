output: main.o operations.o
	g++ -std=c++14 main.o operations.o -o main

main.o: main.cpp operations.h
	g++ -c -std=c++14 main.cpp

operations.o: operations.h operations.cpp
	g++ -c -std=c++14 operations.cpp

build: main.o operations.o
	g++ main.o operations.o -o main.exe
	
run: main.exe