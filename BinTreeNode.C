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

BinTreeNode::BinTreeNode(string lastName, BinTreeNode* rightChild, BinTreeNode* leftChild, BinTreeNode* parent, int NodeCount){
    setLname(lastName);
    setR(rightChild);
    setL(leftChild);
    setP(parent);
    setCount(NodeCount);
}

int BinTreeNode::GetCount(){
    return NodeCount;
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

void BinTreeNode::setLname(string x){
    lastName = x;
}

void BinTreeNode::setCount(int x){
    NodeCount = x;
}

void BinTreeNode::setR(BinTreeNode* x){
    rightChild = x;
}

void BinTreeNode::setL(BinTreeNode* x){
    leftChild = x;
}

void BinTreeNode::setP(BinTreeNode* x){
    parent = x;
}
