#include "BST.h"
#include <iostream>
using namespace std;

/**
* Title : Binary Search Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 2
* Description : BST implementation
*/

BST::BST():rootPtr(NULL){}

BST::BST(const int& rootItem){
    rootPtr = new BSTNode(rootItem);
}

BST::BST(const int& rootItem, const BST* leftTreePtr, 
         const BST* rightTreePtr){
    
    // Copy left subtree
    BSTNode* leftTree = NULL;
    if (leftTreePtr != NULL)
        leftTree = copyTree(leftTreePtr->rootPtr);
    // Copy Binary Search Treesright subtree
    BSTNode* rightTree = NULL;
    if (rightTreePtr != NULL)
        rightTree = copyTree(rightTreePtr->rootPtr); 

    rootPtr = new BSTNode(rootItem, leftTree, rightTree);
}

BST::BST(BSTNode* nodePtr):rootPtr(nodePtr){}

BST::BST(const BST& treePtr){
    rootPtr = copyTree(treePtr.rootPtr);
}

BST::~BST(){
    destroyTree(rootPtr);
}

BSTNode* BST::copyTree(const BSTNode* treePtr) const {
    BSTNode* newTreePtr = NULL;
    // Copy tree nodes during a preorder traversal
    if (treePtr != NULL ) {
        // Copy node
        newTreePtr = new BSTNode(treePtr->getItem());
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    } // end if
    // Else tree is empty
    return newTreePtr;
}

void BST::destroyTree(BSTNode* subTreePtr) {
    if (subTreePtr != NULL ) {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
    } // end if
} // end destroyTree

void BST::setRootData( const int& newData){
    rootPtr->setItem(newData);
}

int BST::getRootData() const{
    return rootPtr->getItem();
}

int BST::getHeightHelper(BSTNode* subTreePtr) const {
    if (subTreePtr == NULL )
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr()));
} // end getHeightHelper

int BST::getHeight() const {
    return getHeightHelper(rootPtr);
}

void BST::insertItem(int key) {
    BSTNode* newNodePtr = new BSTNode(key);
    rootPtr = insertInorder(rootPtr, newNodePtr);
}

BSTNode* BST::insertInorder(BSTNode* subTreePtr, BSTNode* newNodePtr){
    // If the tree is NULL
    if (subTreePtr == NULL)
        return newNodePtr;
    // If the item is greater than root
    else if (subTreePtr->getItem() > newNodePtr->getItem()) {
        BSTNode* tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    // If the item is smaller than root
    else {
        BSTNode* tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

void BST::inorder(BSTNode* treePtr, int* arrayPtr, int &count) const{
   if (treePtr != NULL) {
        // The left
        inorder(treePtr->getLeftChildPtr(), arrayPtr, count);
        int theItem = treePtr->getItem();
        // The parent
        arrayPtr[count] = theItem;
        count++;
        // The right
        inorder(treePtr->getRightChildPtr(), arrayPtr, count);
    } // end if
}

int* BST::inorderTraversal(int& length){
    int* arrayPtr;
    int count = 0;
    // Get length
    length = getNumberOfNodes();
    // Allocate the array
    arrayPtr = new int[length];
    // Call the function
    inorder(rootPtr, arrayPtr, count);
    return arrayPtr;
}

void BST::preorder(BSTNode* treePtr, int* arrayPtr, int &count) const{
   if (treePtr != NULL) {
        // The root
        int theItem = treePtr->getItem();
        arrayPtr[count] = theItem;
        count++;
        // The left
        preorder(treePtr->getLeftChildPtr(), arrayPtr, count);
        // The right
        preorder(treePtr->getRightChildPtr(), arrayPtr, count);
    } // end if
}

int* BST::preorderTraversal(int& length){
    int* arrayPtr;
    int count = 0;
    // Get length
    length = getNumberOfNodes();
    // Allocate the array
    arrayPtr = new int[length];
    // Call the function
    preorder(rootPtr, arrayPtr, count);
    return arrayPtr;
}

int BST::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

int BST::getNumberOfNodesHelper(BSTNode* subTreePtr) const {
    if (subTreePtr == NULL)
        return 0;
    
    return getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) 
           + getNumberOfNodesHelper(subTreePtr->getRightChildPtr()) 
           + 1;
}

void BST::deleteItem(int key){
    rootPtr = removeValue(rootPtr, key);
}

BSTNode* BST::removeValue(BSTNode* subTreePtr, const int target){
    if (subTreePtr == NULL)
        return NULL;
    else if (subTreePtr->getItem() == target){
        // Item is in the root of some subtree
        subTreePtr = removeNode(subTreePtr);
        return subTreePtr;

    }
    else if (subTreePtr->getItem() > target){
        // Search the left subtree
        BSTNode* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;

    }
    else {
        // Search the right subtree
        BSTNode* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target);
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

BSTNode* BST::removeNode(BSTNode* nodePtr){
    if (nodePtr->isLeaf()){
        // Remove leaf from the tree
        delete nodePtr;
        nodePtr = NULL;
        return nodePtr;
    }
    // Child replaces node as the child of nodes parent
    else if (nodePtr->getLeftChildPtr() == NULL){
        BSTNode* nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = NULL;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightChildPtr() == NULL){
        BSTNode* nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = NULL;
        return nodeToConnectPtr;
    }
    else { // Node has two children
        // Find the leftmost node of the right subtree of the entry in Node: it is in the left subtree rooted
        // at Nodes right child
        BSTNode* deletedNode = nodePtr;
        BSTNode* tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), nodePtr);
        nodePtr->setLeftChildPtr(deletedNode->getLeftChildPtr());
        nodePtr->setRightChildPtr(tempPtr);
        delete deletedNode;
        deletedNode=NULL;
        return nodePtr;
    }
}

BSTNode* BST::removeLeftmostNode(BSTNode* nodePtr, BSTNode* &deletedNode){
    if (nodePtr->getLeftChildPtr() == NULL){
        // This is the node you want; it has no left child, but it might have a right subtree
        BSTNode* nodeToConnectPtr = nodePtr->getRightChildPtr();
        nodePtr->setRightChildPtr(NULL);
        deletedNode = nodePtr;
        return nodeToConnectPtr;
    }
    else {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), deletedNode));
        return nodePtr;
    }
}

BSTNode* BST::retrieveItem(int key){
    return findNode(rootPtr, key);
}

BSTNode* BST::findNode(BSTNode* subTreePtr, const int target) const {
    if (subTreePtr == NULL)
        return NULL;
    // The root has key
    else if (subTreePtr->getItem() == target)
        return subTreePtr;
    // The left subtree has key
    else if (subTreePtr->getItem() > target)
        return findNode(subTreePtr->getLeftChildPtr(), target);
    // The right subtree has key
    else
        return findNode(subTreePtr->getRightChildPtr(), target);
}

bool BST::containsSequence(int* seq, int length){
    // Flag shows that we found the first item of the sequence in the tree 
    // and after that it shows that the there is a missed node or not 
    bool flag = false;
    searchSequence(rootPtr, seq, length, flag);
    return length == 0;
}

bool BST::searchSequence(BSTNode* subTreePtr, int* &seq, int &length, bool &flag){
    if (subTreePtr == NULL)
        return true;

    if (length == 0)
        return true;

    cout <<  subTreePtr->getItem() << "-";
    // Checks the flag to understand that whether we have found the first item or not
    if(!flag){
        // If the first item in the sequence is greater than the node, calls for right subtree
        if (seq[0] > subTreePtr->getItem()){
            return searchSequence(subTreePtr->getRightChildPtr(), seq, length, flag);
        }
        // If the first item in the sequence is equal to the node, calls for right subtree
        else if (seq[0] == subTreePtr->getItem()){
            flag = true; // the signal that we found the first item in the sequence
            // To move in the sequence array
            ++seq; 
            --length;
            return searchSequence(subTreePtr->getRightChildPtr(), seq, length, flag);
        }
        // If the first item in the sequence is smalller than the node, calls fo both left and right
        // because it has nodes that are in the sequence at both subtrees 
        else {
            bool temp = searchSequence(subTreePtr->getLeftChildPtr(), seq, length, flag);
            // If length is zero, exits the function
            if (length == 0)
                return true;
            // If flag or temp is false, exits the function with false
            // flag is false means that it has missed some nodes
            // temp is false means that it can't find the nodes
            if (!flag || !temp)
                return false;
            // If the item in the node and the firts item of the sequence is not equal, 
            // then it means that the sequence missed the node
            if (seq[0] != subTreePtr->getItem()){
                flag = false;
                return false;
            }
            ++seq;
            --length;
            return searchSequence(subTreePtr->getRightChildPtr(), seq, length, flag);
        }
    }
    else {
        // If the flag is false (we have not found the first item of the node yet) then it should look both for left and right
        bool temp = searchSequence(subTreePtr->getLeftChildPtr(), seq, length, flag);
        // If length is zero, exits the function
        if (length == 0)
            return true;
        // If flag or temp is false, exits the function with false
        // flag is false means that it has missed some nodes
        // temp is false means that it can't find the nodes
        if (!flag || !temp)
            return false;
        // If the item in the node and the firts item of the sequence is not equal, 
        // then it means that the sequence missed the node
        if (seq[0] != subTreePtr->getItem()){
            flag = false;
            return false;
        }
        ++seq;
        --length;
        return searchSequence(subTreePtr->getRightChildPtr(), seq, length, flag);
    
    }
}

int BST::countNodesDeeperThan(int level){
    return countNodesDeeperThanRecursion(rootPtr, level);
}

int BST::countNodesDeeperThanRecursion(BSTNode* subTreePtr, int level){
    if (subTreePtr == NULL)
        return 0;
    // Sums the left and right
    int left = countNodesDeeperThanRecursion(subTreePtr->getLeftChildPtr(), level - 1);
    int right = countNodesDeeperThanRecursion(subTreePtr->getRightChildPtr(), level - 1);
    int sum = left + right;
    // If the node at greater than level add to sum
    if (level < 2)
        sum++;
    return sum;

}

int BST::maxBalancedHeight(){
    return maxBalancedHeightRecursion(rootPtr);
}

int BST::maxBalancedHeightRecursion(BSTNode* subTreePtr){
    if (subTreePtr == NULL)
        return 0;
    // Gets the left and the right
    int left = maxBalancedHeightRecursion(subTreePtr->getLeftChildPtr());
    int right = maxBalancedHeightRecursion(subTreePtr->getRightChildPtr());

    // If right and left are equal adds one to the height
    if (left == right)
        return left + 1;
    
    // Returns the minimum of the height of the left and right subtrees 
    // and adds 2 as 1 from the parent and 1 from the posibble height
    else if (left - right > 0)
        return right + 2;
    else
        return left + 2;
}