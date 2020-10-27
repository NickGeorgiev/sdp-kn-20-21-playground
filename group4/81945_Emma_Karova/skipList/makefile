root= $(shell git rev-parse --show-toplevel)

output: skipListMain.o skipList.o
	g++ -std=c++14 skipListMain.o skipList.o -o output

skipListMain.o: skipListMain.cpp SkipList.h
	g++ -c -std=c++14 skipListMain.cpp

skipList.o: skipList.h skipList.cpp
	g++ -c -std=c++14 skipList.cpp 

build_tests: unitTests.o skipList.o
	g++ unitTests.o skipList.o -o unitTests.exe

unitTests.o: unitTests.cpp
	g++ -I $(root) -c unitTests.cpp

run_tests:
	./unitTests.exe
