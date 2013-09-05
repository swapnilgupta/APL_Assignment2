#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Dictionary.h"
struct node
{
int data;
node *left;
node *right;
};
node *tree;
tree=NULL;

class BinarySearchTree : public Dictionary {

    public:
	  node *tree=NULL;
	  void preorder(node *tree);
	  void inorder(node *tree);
	  void postorder(node *tree);
          void Insert(int val);
          bool Delete(int val);
          bool Search(int val);
	  void ClearADT();
          void Display();
};

#endif
