#ifndef _BTree_H
#define _BTree_H
/*---------------------------------------------------------------------------------
    Making of the tree. This is a Binary Tree H file with the outline of all the meathods that can be called on the tree. 
    
Alban Schneider 
3/14/17
---------------------------------------------------------------------------------*/

#include <iostream>
#include <set>
#include "BinTreeNode.H"

using namespace std;

class BTree{ //BTree stands for Binary Tree.

    public: 
    
    BTree(); //This is to set up to later variables. 
        


BinTreeNode* Insert(string lastName); 
    
BinTreeNode* FindParent(string lastName, BinTreeNode* start);

/* Remove is a meathod that searches for a given last name in the tree, then if found removes it from the tree. If the name is not found an error message will be printed for the user. 
Pre: The tree can't be empty. 
Post: If found the tree will lose a Node and in some cases need to be modified. The Number of Nodes will decrease if found. */

BinTreeNode* Remove(string lastName);

/* Search is just like it sounds. This meathod looks through the tree for a certain name contained in the tree. This meathod will return a Node if the last name and first name are in the tree. If not found an error message will be printed for the user. 
Pre:None
Post: A Node will be out put, or an error message. */

BinTreeNode* Search(string lastName);
BinTreeNode* SearchHelper(string lastName, BinTreeNode* start);

/* PCount is a meathod that returns the number of people inserted. 
Pre: None
Post: An int will return with the number of people total. */

int PCount();
    
/* NumOfFam is a meathod that returns the number of Nodes with unique last names contained in the tree. 
Pre: None
Post: An int will return with the number of Nodes. */

int NumOfFam();

/* Print is a meathod that goes through the tree and prints the Nodes in In-Order traversal. 
Pre: None
Post: Each Node will be printed, unless there is no Nodes. In that case an error message will be prrinted. */

void Print(BinTreeNode* root);
    
BinTreeNode* GetRoot(); 
    
void SetRoot(BinTreeNode* x);
    
int personcount;
    
int treeSize;
    private:
    BinTreeNode* root; //This is the first Node input and is commonly the start.

   // Variables:
//BinTreeNode* root; //This is the first Node input and is commonly the start. 
};

#endif