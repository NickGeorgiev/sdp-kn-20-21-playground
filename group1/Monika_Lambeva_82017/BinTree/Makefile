root= $(shell git rev-parse --show-toplevel)

# Step to build the files with specs given we have a file named `tests`. You can change the filename if you want
# If the code uses some other user-defined classes/libraries, their code should be compiled too and the object files should be provided
build_tests: mainTests.o BinTree.o
	g++ mainTests.o BinTree.o -o tests.exe 

# Given the file with specs is named `tests`, we need to produce the object file.
# For every object file that needs to be created we need such step
mainTests.o: mainTests.cpp BinTree.h
	g++ -I $(root) -c mainTests.cpp

# Optional step. You can execute the file directly from the console
run_tests:
	./tests.exe
