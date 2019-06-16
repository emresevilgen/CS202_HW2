#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>
using namespace std;

/**
* Title : Binary Search Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 2
* Description : BST header file
*/

class BST {
private:
    BSTNode* rootPtr;

protected:
    //------------------------------------------------------------
    //  Protected Utility Methods Section:
    //  Recursive helper methods for the public methods.
    //------------------------------------------------------------
    int getHeightHelper(BSTNode* subTreePtr) const ;
    int getNumberOfNodesHelper(BSTNode* subTreePtr) const ;

    // Recursively deletes all nodes from the tree.
    void destroyTree(BSTNode* subTreePtr);

    //------------------------------------------------------------
    //  Protected Utility Methods Section:
    //  Recursive helper methods for the public methods.
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    BSTNode* insertInorder(BSTNode* subTreePtr, BSTNode* newNodePtr);

    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    BSTNode* removeValue(BSTNode* subTreePtr, const int target);

    // Removes a given node from a tree while maintaining a
    // binary search tree.
    BSTNode* removeNode(BSTNode* nodePtr);

    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    BSTNode* removeLeftmostNode(BSTNode* nodePtr, BSTNode* &deletedNode);
   
    // Returns a pointer to the node containing the given value,
    // or nullptr if not found.
    BSTNode* findNode(BSTNode* treePtr, const int target) const ;

    // Copies the tree rooted at treePtr and returns a pointer to the copy.
    BSTNode* copyTree(const BSTNode* treePtr) const ;
    
    // Recursive traversal helper methods:
    void inorder(BSTNode* treePtr, int* arrayPtr, int &count) const ;
    void preorder(BSTNode* treePtr, int* arrayPtr, int &count) const ;

    bool searchSequence(BSTNode* subTreePtr, int* &seq, int &length, bool &flag);

    int countNodesDeeperThanRecursion(BSTNode* subTreePtr, int level);

    int maxBalancedHeightRecursion(BSTNode* subTreePtr);


    
public:
//------------------------------------------------------------
//  Constructor and Destructor Section.
//------------------------------------------------------------
	BST();
	BST(const int& rootItem);
    BST(const int& rootItem, const BST* leftTreePtr, const BST* rightTreePtr);
    BST(const BST& treePtr);
    BST(BSTNode* nodePtr);
    ~BST();

//------------------------------------------------------------
//  Other expected functions
//------------------------------------------------------------
    bool containsSequence(int* seq, int length);
    int countNodesDeeperThan(int level);
    int maxBalancedHeight();

//------------------------------------------------------------
//  Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
    bool isEmpty() const ;
    int getHeight() const ;
    int getNumberOfNodes() const ;
    int getRootData() const;
    void setRootData( const int& newData);

    void insertItem(int key);
    void deleteItem(int key);

    BSTNode* retrieveItem(int key);

//------------------------------------------------------------
//  Public Traversals Section.
//------------------------------------------------------------
    int* inorderTraversal(int& length);
    int* preorderTraversal(int& length);


};
#endif