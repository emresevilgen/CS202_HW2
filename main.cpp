#include <iostream>
#include "BST.h"
using namespace std;

/**
* Title : Binary Search Trees
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 2
* Description : Main function
*/

int main(){
    BST* bst1 = new BST(8);
    bst1->insertItem(4);
    bst1->insertItem(13);
    bst1->insertItem(3);
    bst1->insertItem(6);
    bst1->insertItem(12);
    bst1->insertItem(15);
    bst1->insertItem(1);
    bst1->insertItem(5);
    bst1->insertItem(10);
    bst1->insertItem(14);
    bst1->insertItem(2);

    BST* bst2 = new BST(1);
    BST* bst3 = new BST();
    BST* bst4 = new BST(*bst1);  

    int length;
    int* array = bst1->inorderTraversal(length);
    cout << "Tree 1 by BST(const int& rootItem):\n" ;
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;

    cout << "\n--------" << endl;

    array = bst2->inorderTraversal(length);
    cout << "Tree 2 by BST(const int& rootItem):\n" ;
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;

    cout << "\n--------" << endl;
    
    array = bst3->inorderTraversal(length);
    cout << "Tree 3 BST():\n" ;
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;

    cout << "\n--------" << endl;

    array = bst4->inorderTraversal(length);
    cout << "Tree 4 by BST(const BST& treePtr):\n" ;
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;

    cout << "\n--------" << endl;

    cout << "Delete 13 from Tree 4:\n";
    bst4->deleteItem(13);
    array = bst4->inorderTraversal(length);
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;
    cout << "\n--------" << endl;

    cout << "Retrieve 1 from Tree 4:\n";
    BSTNode* temp = bst4->retrieveItem(1);
    if (temp == NULL)
        cout << temp;
    else
        cout << temp->getItem();
    cout << "\n--------" << endl;

    cout << "Retrieve 1 from Tree 3:\n";
    temp = bst3->retrieveItem(1);
    if (temp == NULL)
        cout << "NULL";
    else
        cout << temp->getItem();
    cout << "\n--------" << endl;

    cout << "inorderTraversal of Tree 1:\n";
    array = bst1->inorderTraversal(length);
    for(int i = 0; i < length; i++)
        cout << array[i] << " ";
    delete [] array;
    cout << "\n--------" << endl;

    int arr1 [] = {1, 2, 3, 4, 5, 6};
    int* array1 = arr1;
    int arr2 [] = {10, 12, 13, 15};
    int* array2 = arr2;
    int arr3 [] = {10, 11, 12};
    int* array3 = arr3;

    cout << "containsSequence([1, 2, 3, 4, 5, 6], 6) of Tree 1:\n";
    if (bst1->containsSequence(array1, 6))
            cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;

    cout << "containsSequence([10, 12, 13, 15], 4) of Tree 1:\n";
    if (bst1->containsSequence(array2, 4))
        cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;

    cout << "containsSequence([10, 11, 12], 3) of Tree 1:\n";
    if (bst1->containsSequence(array3, 3))
        cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;
    
    cout << "containsSequence([1, 2, 3, 4, 5, 6], 6) of Tree 2:\n";
    if (bst2->containsSequence(array1, 6))
            cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;

    cout << "containsSequence([1, 2, 3, 4, 5, 6], 6) of Tree 3:\n";
    if (bst3->containsSequence(array1, 6))
            cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;

    cout << "containsSequence([1, 2, 3, 4, 5, 6], 6) of Tree 4:\n";
    if (bst4->containsSequence(array1, 6))
            cout << "True";
    else
        cout << "False";
    cout << "\n--------" << endl;

    cout << "countNodesDeeperThan(3) of Tree 1:\n";
    cout << bst1->countNodesDeeperThan(3);
    cout << "\n--------" << endl;

    cout << "countNodesDeeperThan(2) of Tree 1:\n";
    cout << bst1->countNodesDeeperThan(2);
    cout << "\n--------" << endl;

    cout << "countNodesDeeperThan(3) of Tree 2:\n";
    cout << bst2->countNodesDeeperThan(3);
    cout << "\n--------" << endl;

    cout << "countNodesDeeperThan(3) of Tree 3:\n";
    cout << bst3->countNodesDeeperThan(3);
    cout << "\n--------" << endl;

    cout << "countNodesDeeperThan(3) of Tree 4:\n";
    cout << bst4->countNodesDeeperThan(3);
    cout << "\n--------" << endl;

    cout << "maxBalancedHeight() of Tree 1:\n";
    cout << bst1->maxBalancedHeight();
    cout << "\n--------" << endl;

    cout << "maxBalancedHeight() of Tree 2:\n";
    cout << bst2->maxBalancedHeight();
    cout << "\n--------" << endl;

    cout << "maxBalancedHeight() of Tree 3:\n";
    cout << bst3->maxBalancedHeight();
    cout << "\n--------" << endl;

    cout << "maxBalancedHeight() of Tree 4:\n";
    cout << bst4->maxBalancedHeight();
    cout << "\n--------" << endl;

    delete bst1;
    delete bst2;
    delete bst3;
    delete bst4;

    cout << "end...\n";
    return 0;
}