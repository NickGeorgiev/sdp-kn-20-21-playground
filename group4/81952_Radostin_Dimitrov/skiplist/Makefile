output: main.o skiplist.o
	g++ -std=c++14 main.o skiplist.o

main.o: main.cpp skiplist.h
	g++ -c -std=c++14 main.cpp

skiplist.o: skiplist.h skiplist.cpp
	g++ -c -std=c++11 skiplist.cpp
