/*------------------------------------------------------------------
A test driver for the disaster binary tree project.

Written by Alban Schneider
------------------------------------------------------------------*/

#include <iostream>
#include "BTree.H"
//#include "BinTreeNode.H"

using namespace std;

enum EntryCode {Insert, Remove , COUNT, Search, PRINT, QUIT};


int main () {
  // Declare some useful variables
  int response;
 // BinTreeNode* results;
  string newPerson;

  // Instantiate/construct a binary tree. 
  BTree* registered = new BTree();
    BinTreeNode* results;
    BinTreeNode* trueroot = registered -> GetRoot();
  // Get the user's intention
  cout << "\n Enter a number: \n 0: Insert a new survior \n 1: Remove a person from a family \n 2: Get total number of people and families present.\n 3: Search for a last name \n 4: Print all families in the program. \n enter code: ";
  cin >> response;
  while ((response >= Insert) && (response <= 5)) {
    switch (response) {
    
    case Insert:
      cout << "\nEnter the last name of the survior: ";
      cin >>newPerson;
     results = registered -> Insert(newPerson);
      cout<<" A person in the " << results -> GetLname() << " family was added to the registered."<<endl;
      break;
      
    case Remove:
    cout << "\nEnter the last name of the survior you wish to remove: ";
    cin >> newPerson;
      results = registered -> Remove(newPerson);
      if(results != NULL){
      cout<<results -> GetLname() << " has been reduced by one member."<<endl;
      }
      else{cout<<"There is no family registered by that name."<<endl;}
      break;
      
    case COUNT:
    if(registered -> treeSize != 0){
      cout << "\nThere are " << registered -> NumOfFam() << " families.";
      cout << "\nThere are " << registered -> PCount() << " surviors.";
      }
      else{cout << "There are no surviors."<< endl;}
      break;
      
    case Search:
    cout << "\nEnter the last name of the survior: ";
      cin >>newPerson;
      results = registered -> Search(newPerson);
      if(results != NULL){
          cout << "There are "<< results -> GetCount() << " people with that last name." << endl;
      }
    else{cout << "There are no surviors with that last name." << endl;}
      break;
            
	case PRINT:
	  registered -> Print(trueroot -> GetRC());
	  break;
      }
    

    // Get the user's intention
    cout << "\nEnter 0: Insert a new survior \n 1: Remove a person from a family \n 2: Get total number of people and families present.\n 3: Search for a last name \n 4: Print all families in the program. \n enter code: ";
    cin >> response;
  }
  delete registered;
  cout << endl << endl;
  return(0);
}
