# Title : Binary Search Trees
# Author : Munib Emre Sevilgen
# ID: 21602416
# Section : 1
# Assignment : 2
# Description : makefile



hw2: main.o BST.o BSTNode.o
	g++ main.o BST.o BSTNode.o -o hw2
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

BST.o: BST.cpp BST.h
	g++ -c BST.cpp

BSTNode.o: BSTNode.cpp BSTNode.h
	g++ -c BSTNode.cpp

clean:
	rm hw2
	
