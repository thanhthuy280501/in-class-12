#include <iostream>
using namespace std;

#include "link.h"
#include "llist.h"
#include "llist.cpp"

//*****************************************************************
// Program:	ltmenu.cpp
// Author:	S. Turner
// Date:	December 2009
//
// A program that presents a menu of List functions to use.  It
// accepts keyboard input directing it to perform the various
// functions available in the interface.
//*****************************************************************
int main() {

  LList L1;				// An integer linked list
  string choice;			// For commands
  int tmp;				// Secondary command
  bool success;				// Return value from certain list
					// commands

  cout << "Options are" << endl;
  cout << "insert (val)" << endl;
  cout << "append (val)" << endl;
  cout << "remove" << endl;
  cout << "setstart  setend" << endl;
  cout << "prev        next" << endl;
  cout << "setpos (val)" << endl;
  cout << "getval" << endl;
  cout << "print" << endl;
  cout << "Enter a choice (or 'quit'):  ";
  cin >> choice;

  int count = 0;
  while (choice != "quit") {
//**************************************************************
//  A long series of if/then/elses determining what they typed
//  and doing as directed.
//**************************************************************
    if (choice == "insert") {
      cin >> tmp;
      L1.insert(tmp);
      cout << "L1.insert("<<tmp<<"); ----->\t\t";
      L1.print();
    }
    else if (choice == "append") {
      cin >> tmp;
      L1.append(tmp);
      cout << "L1.append("<<tmp<<"); ----->\t\t";
      L1.print();
    }
    else if (choice == "setpos") {
      cin >> tmp;
      success = L1.setPos(tmp);
      if (!success) cout << "Invalid location!" << endl;
      cout << "L1.setPos("<<tmp<<"); ----->\t\t";
      L1.print();
    }
    else if (choice == "remove") {
      success = L1.remove(tmp);
      if (success) cout << "Removed the value " << tmp << endl;
      else         cout << "Remove FAILED!" << endl;
      cout << "L1.remove(tmp); ----->\t\t";
      L1.print();
    }
    else if (choice == "setstart") {
      L1.setStart();
      cout << "L1.setStart(); ----->\t\t";
      L1.print();
    }
    else if (choice == "setend") {
      L1.setEnd();
      cout << "L1.setEnd(); ----->\t\t";
      L1.print();
    }
    else if (choice == "next") {
      L1.next();
      cout << "L1.next(); ----->\t\t";
      L1.print();
    }
    else if (choice == "prev") {
      L1.prev();
      cout << "L1.prev(); ----->\t\t";
      L1.print();
    }
    else if (choice == "getval") {
      L1.getValue(tmp);
      cout << "Got the value " << tmp << endl;
      cout << "L1.getValue(tmp); ----->\t\t";
      L1.print();
    }
    else if (choice == "print") {
      cout << "L1.print(); ----->\t\t";
      L1.print();
    }
	  else if ( choice == 'search'){
		  cin >> tmp;
		  L1.search (tmp); // doesnt bother with boolean return value
		  sucess = L1.getValue(tmp);
		  if (sucess)
			  cout<< "Found" << tmp << 
    cout << endl;

//*******************************************************************
//  Finally, just output the simplified menu (once every 5) and
//  get another choice.
//*******************************************************************
    count++;
    if (count == 5) {
      cout << "Options: insert append remove setstart setend next prev setpos getval print" << endl;
      count = 0;
    }
    cout << "Enter a choice (or 'quit'):  ";
    cin >> choice;
  }
  return 0;
}
