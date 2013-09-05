all:dict

dict:main.o dictionary.o bst.o rbt.o
	g++ main.o dictionary.o bst.o rbt.o -o dict

main.o:main.cpp 
	g++ -c main.cpp

dictionary.o:Dictionary.h Dictionary.cpp
	g++ -c Dictionary.cpp -o dictionary.o

bst.o:BinarySearchTree.cpp BinarySearchTree.h 
	g++ -c BinarySearchTree.cpp -o bst.o

rbt.o:RedBlackTree.cpp RedBlackTree.h
	g++ -c RedBlackTree.cpp -o rbt.o

clean:
	rm -f *.o
