/*---------------------------------------------------------------------------------
    BTree.C is the code that will be execcuted when the user calls them. 
    
Alban Schneider 
3/14/17
---------------------------------------------------------------------------------*/

#include <iostream>
#include "BTree.H"
#include "BinTreeNode.H"

using namespace std;

BTree::BTree(){
    treeSize = 0;
    personcount = 0;
    root = NULL;
}

//BTree::~BTree(){}


/*Insert is a meathod that adds a person's name to the tree. If the person's last name is already there their first name will be added and the count will increase. If the last name is not in the tree then a new Node will be created and put in a proper location within the tree. 
Pre: None
Post: The tree will not be empty. A new node may be created and/or the count will go up.*/

BinTreeNode* BTree::Insert(string lastName){
    BinTreeNode* temp = new BinTreeNode (lastName,NULL,NULL,NULL,0);
    BinTreeNode* parent = FindParent(lastName, root);
    if(parent != NULL){
    temp -> setP(parent);
    if(parent -> GetLname() > temp -> GetLname()){
        parent  -> setR(temp);
    }
    else if (parent -> GetLname() < temp -> GetLname()){
        parent -> setL(temp);}
    }
    temp -> setCount(temp -> GetCount()+1);
    treeSize++;
    personcount++;
    SetRoot(temp);
    return temp;
}

BinTreeNode* BTree::FindParent(string lastName, BinTreeNode* start){
    if(start != NULL){
        if(start -> GetLname() > lastName){
            if(start -> GetRC() == NULL){
                return start;
            }
            else{start = FindParent(lastName, start -> GetRC());
                return start;}
        }
        else if(start -> GetLname() < lastName){
            if(start -> GetLC() == NULL){
                return start;
            }
            else{start = FindParent(lastName, start -> GetLC());
                return start;}
        }
    }
    else {
        
    }
    return NULL;
}

/* Remove is a meathod that searches for a given last name in the tree, then if found removes it from the tree. If the name is not found an error message will be printed for the user. 
Pre: The tree can't be empty. 
Post: If found the tree will lose a Node and in some cases need to be modified. The Number of Nodes will decrease if found. */

BinTreeNode* BTree::Remove(string lastName){
    BinTreeNode* temp = Search(lastName);
    if (temp != NULL && temp -> GetCount() >= 0){
        temp -> setCount(temp -> GetCount() - 1);
        personcount--;
        return temp;}
    
    else {
        cout<<"No family is registered."<<endl;
        return temp;
    }
}

/* Search is just like it sounds. This meathod looks through the tree for a certain name contained in the tree. This meathod will return a Node if the last name and first name are in the tree. If not found an error message will be printed for the user. 
Pre:None
Post: A Node will be out put, or an error message. */

BinTreeNode* BTree::Search(string lastName){
    if (root == NULL){
        return NULL;
    }
    BinTreeNode* temp = SearchHelper(lastName, root);
    return temp;
}

BinTreeNode* BTree::SearchHelper(string lastName, BinTreeNode* start){
    if (start -> GetLname() == lastName){
        return start;
    }
    else if (start -> GetLname() < lastName){
        start = SearchHelper(lastName, start -> GetRC());
        return start;
    }
    else if (start -> GetLname() > lastName){
        start = SearchHelper(lastName, start -> GetLC());
        return start;
    }
    else{return start;}
}
    
/* NumOfFam is a meathod that returns the number of Nodes with unique last names contained in the tree. 
Pre: None
Post: An int will return with the number of Nodes. */

int BTree::NumOfFam(){
    return treeSize;
}

/* PCount is a meathod that returns the number of people total that have been inputed in the tree. 
Pre: None
Post: An int will return with the number people total. */

int BTree::PCount(){
    return personcount;
}


/* Print is a meathod that goes through the tree and prints the Nodes in In-Order traversal. 
Pre: None
Post: Each Node will be printed, unless there is no Nodes. In that case an error message will be prrinted. */

void BTree::Print(BinTreeNode* start){
    if(start != NULL){
        if(start -> GetLC() != NULL){
            Print(start -> GetLC());}
        else{
            cout<<start -> GetLname()<<endl;
            cout<<"There are " + start -> GetCount() << start -> GetLname()<<endl;}
        if(start -> GetRC()){
            Print(start -> GetRC());
        }
        else{
            cout<<start -> GetLname()<<endl;
            cout<<"There are " + start -> GetCount() << start -> GetLname()<<endl;
        }
        }
    else{cout<<"There are no surviors."<<endl;}
    }

BinTreeNode* BTree::GetRoot(){
    return root;
}

void BTree::SetRoot(BinTreeNode* x){
    root = x;
}
