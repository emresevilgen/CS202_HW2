#ifndef BSTNODE_H
#define BSTNODE_H
#include <cstddef>
/**
* Title : Binary Search Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 2
* Description : BSTNode header file
*/

class BSTNode {
private:
	int item;                   // Data portion
	BSTNode* leftChildPtr;  	// Pointer to left child
	BSTNode* rightChildPtr; 	// Pointer to right child

public:
	BSTNode();
    BSTNode(const int& anItem);
	BSTNode(const int& anItem, BSTNode* leftPtr, BSTNode* rightPtr);
            
    void setItem( const int& anItem);
    int getItem() const ;
    bool isLeaf() const ;
    BSTNode* getLeftChildPtr() const ;
    BSTNode* getRightChildPtr() const ;
    void setLeftChildPtr(BSTNode* leftPtr);
    void setRightChildPtr(BSTNode* rightPtr);
	
};
#endif
