root= $(shell git rev-parse --show-toplevel)

output: skiplist_tests.o
	g++ -std=c++14 skiplist_tests.o output

main.o: skiplist_tests.cpp sharedSpecs.h
	g++ -c -std=c++14 main.cpp

SkipList.o: skiplist_tests.cpp
	g++ -c -std=c++14 skiplist_tests.cpp

build_tests: skiplist_tests.o
	g++ skiplist_tests.o skiplist_tests.exe

tests.o: skiplist_tests.cpp
	g++ -I $(root) -c skiplist_tests.cpp

run_tests:
	./skiplist_tests.exe