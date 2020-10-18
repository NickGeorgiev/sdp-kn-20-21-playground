output: main.o SkipList.o
	g++ -std=c++14 main.o SkipList.o -o output

main.o: main.cpp SkipList.h
	g++ -c -std=c++14 main.cpp

SkipList.o: SkipList.h SkipList.cpp
	g++ -c -std=c++14 SkipList.cpp