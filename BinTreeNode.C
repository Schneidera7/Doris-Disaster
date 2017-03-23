/*------------------------------------------------------------------------------------------------------
BinTreeNode.C is the C file that creates the class for our Binary Tree Nodes. 

Alban Schneider 
3/13/17
-------------------------------------------------------------------------------------------------------*/

#include "BinTreeNode.H"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cstdlib>

BinTreeNode::BinTreeNode(string lastName, BinTreeNode* rightChild, BinTreeNode* leftChild, BinTreeNode* parentPointer, int nodeCount){
    SetLname(lastName);
    SetR(rightChild);
    SetL(leftChild);
    SetP(parent);
    SetCount(nodeCount);
}

int BinTreeNode::GetCount(){
    return nodeCount;
}

string BinTreeNode::GetLname(){
    return lastName;
}

BinTreeNode* BinTreeNode::GetLC(){
    return leftChild;
}

BinTreeNode* BinTreeNode::GetRC(){
    return rightChild;
}

BinTreeNode* BinTreeNode::GetP(){
    return parent;
}


//BinTreeNode::~BinTreeNode(){
//}

void BinTreeNode::SetLname(string x){
    lastName = x;
}

void BinTreeNode::SetCount(int x){
    nodeCount = x;
}

void BinTreeNode::SetR(BinTreeNode* x){
    rightChild = x;
}

void BinTreeNode::SetL(BinTreeNode* x){
    leftChild = x;
}

void BinTreeNode::SetP(BinTreeNode* x){
    parentPointer = x;
}
