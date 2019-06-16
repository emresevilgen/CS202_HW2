#include   "BSTNode.h"

/**
* Title : Binary Search Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 2
* Description : BSTNode implementation
*/

BSTNode::BSTNode(){}

BSTNode::BSTNode(const int& anItem):item(anItem){
    rightChildPtr = NULL;
    leftChildPtr = NULL;
}

BSTNode::BSTNode(const int& anItem, BSTNode* leftPtr, BSTNode* rightPtr)
                :item(anItem),leftChildPtr(leftPtr),rightChildPtr(rightPtr){}

void BSTNode::setItem( const int& anItem){
    item = anItem;
}

int BSTNode::getItem() const{
    return item;
}

bool BSTNode::isLeaf() const{
    if (rightChildPtr == NULL && leftChildPtr == NULL)
        return true;
    return false;
}

BSTNode* BSTNode::getLeftChildPtr() const {
    return leftChildPtr;
}

BSTNode* BSTNode::getRightChildPtr() const {
    return rightChildPtr;
}

void BSTNode::setLeftChildPtr(BSTNode* leftPtr){
    leftChildPtr = leftPtr;
}

void BSTNode::setRightChildPtr(BSTNode* rightPtr){
    rightChildPtr = rightPtr;

}

