root= $(shell git rev-parse --show-toplevel)

output: main.o slist.o
	g++ -std=c++14 main.o slist.o -o output

main.o: main.cpp slist.h
	g++ -c -std=c++14 main.cpp

slist.o: slist.h slist.cpp
	g++ -c -std=c++14 slist.cpp

build_tests: tests.o slist.o
	g++ tests.o slist.o -o tests.exe

tests.o: tests.cpp
	g++ -I $(root) -c tests.cpp

run_tests:
	./tests.exe