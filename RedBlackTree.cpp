#include "RedBlackTree.h"
#include <iostream>

void RedBlackTree::Insert(int val)
{
     std::cout << val << "Inside RBT::Insert()\n";
}

bool RedBlackTree::Delete(int val)
{
     std::cout << val << "Inside RBT::Delete()\n";
     return 1;
}

bool RedBlackTree::Search(int val)
{
     std::cout << val << "Inside RBT::Search()\n";
     return 1;
}

void RedBlackTree::ClearADT()
{
     std::cout <<"Inside RBT::ClearADT()\n";
}
 
void RedBlackTree::Display()
{
     std::cout <<"Inside RBT::Display()\n";
}
