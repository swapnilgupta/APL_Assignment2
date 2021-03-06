#include "BinarySearchTree.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
node *tree;
using namespace std;
void BinarySearchTree :: preorder(node *t){
    if( t!=NULL){
        cout<<" "<< t->data;
        preorder(t->left);
        preorder(t->right);
    }
}

void BinarySearchTree :: inorder(node *t){
    if( t!=NULL){
        inorder( t->left);
        cout<<" "<< t->data;
        inorder(t->right);
    }
}

void BinarySearchTree :: postorder(node *t){
    if( t!=NULL){
        postorder( t->left);
        postorder( t->right);
        cout<<" "<<t->data;
    }
}

void BinarySearchTree::Insert(int val)
{

		if(tree==NULL)
               	{
                    tree=new node;
                    tree->left=tree->right=NULL;
                    tree->data=val;
                   
               	}
               	else
		{
		node *parent, *curr;
                curr = tree;

   
 		// Find the Node's parent

		while(curr)
		    {
	            parent = curr;
		    if(val > curr->data) curr = curr->right;
		    else curr = curr->left;
    		    }
     node *t;
     t=new node;
     t->left=NULL;
     t->right=NULL;

	if(t->data < parent->data)
		parent->left = t;
    	else
       		parent->right = t;
		}
}

bool BinarySearchTree::Delete(int val)
{
     if(tree==NULL)
	return false;
     else
	{
bool found=false;
	    //Locate the element
    	node* curr;
    	node* parent;
    	curr = tree;
    
    	while(curr != NULL)
   	{
         if(curr->data == val)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(val>curr->data) curr = curr->right;
             else curr = curr->left;
         }
    	}
    if(!found)
        return false; // If the element you want to delete is not present in the tree then it returns 0
    


	// 3 cases :

		// 1. We're removing a leaf node
	    	// 2. We're removing a node with a single child
    		// 3. we're removing a node with 2 children

    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return true;
    }


//We're looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
	{
        	if(parent->left == curr) 
			parent->left = NULL;
        	else 
			parent->right = NULL;
 		 delete curr;
 		 return true;
    	}


    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element

            if((curr->right)->left != NULL)
            {
                node* lcurr;
                node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	       curr->right = tmp->right;
               delete tmp;
           }

        }
	return true;
    }


	}
}

bool BinarySearchTree::Search(int val)
{
     if(tree==NULL)
		return false;
     else 
	{
	node *temp;
	temp=tree;
	while(temp->data!=val || temp==NULL)
	{
	if(temp->data<val)
		temp=temp->right;
	else
		temp=temp->left;
	}
    
    if(temp->data=val)
	return true;
    else
	return false;
       }
}


void BinarySearchTree::ClearADT()
{
     delete tree;
}
 
void BinarySearchTree::Display()
{
     inorder(tree);
}
