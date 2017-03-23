#ifndef _BinTreeNode_H
#define _BinTreeNode_H

/*----------------------------------------------------------------------------------------------
This is the class meant to create the Nodes for the Binary Tree. These Nodes will contain specifically the six fields needed for this project. (First Name, Last Name, Count, Right Child, Left Child, Parent)
----------------------------------------------------------------------------------------------*/

#include <iostream>
#include <set>

using namespace std;

class BinTreeNode {
    
    public: 
    
    BinTreeNode(string lastName, BinTreeNode* rightChild, BinTreeNode* leftChild, BinTreeNode* parentPointer, int count);
    
    void SetLname(string x);
    
    void SetR(BinTreeNode* x);
    
    void SetP(BinTreeNode* x);
        
    void SetL(BinTreeNode* x);
    
    void SetCount(int x);
    
    
    int GetCount();
    
    string GetLname();
    
    BinTreeNode* GetLC();
    
    BinTreeNode* GetRC();
    
    BinTreeNode* GetP();
    
    private: 
    
    string lastName; 
    
    int nodeCount; // Keeps track of the number of people with this last name. 
    
    BinTreeNode* parentPointer; //The Node above the current Node. 
    
    BinTreeNode* rightChild; //The next last name that is entered that comes after the current Node. 
    
    BinTreeNode* leftChild; // The next last name entered that comes before the current Node. 
    
    
};
#endif
