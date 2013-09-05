#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Dictionary.h"

class RedBlackTree : public Dictionary {

    public:
          void Insert(int val);
          bool Delete(int val);
          bool Search(int val);
	  void ClearADT();
          void Display();
};

#endif
