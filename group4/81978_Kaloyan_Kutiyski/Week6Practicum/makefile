main.out: main.o BalancedBinaryTree.o ListOrderable.o
	g++ main.o BalancedBinaryTree.o ListOrderable.o -o main.out
	rm *.o

BalancedBinaryTree.o:
	g++ -c BalancedBinaryTree/BalancedBinaryTree.cpp

ListOrderable.o:
	g++ -c ListOrderable/ListOrderable.cpp

main.o:
	g++ -c main.cpp