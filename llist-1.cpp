//**********************************
// Linked List implementation file.
//**********************************

#include "llist.h"

//************************************************************************
// Returns the link nodes to the free store.
// note that it's inline.
//************************************************************************
void LList::removeall() {
  while(head != NULL) {
    fence = head;
    head = head->next;
    delete fence;
  }
}

//************************************************************************
// Insert a value at the current fence position.  This
// function returns true if successful and false otherwise.
//************************************************************************
bool LList::insert(const int item) {
  fence->next = new Link(item, fence->next);  
  if (tail == fence) tail = fence->next;  // New tail
  rightcnt++;
  return true;
}

//************************************************************************
// Append a value to the end of the list.  This
// function returns true if successful and false otherwise.
//************************************************************************
bool LList::append(const int item) {
  tail = tail->next = new Link(item, NULL);
  rightcnt++;
  return true;
}

//************************************************************************
// Remove and return first int in right partition
// This function returns true if successful and false otherwise.
//************************************************************************
bool LList::remove(int& it) {
  if (fence->next == NULL)
    return false;
  it = fence->next->element;
  Link* ltemp = fence->next;
  fence->next = ltemp->next;
  if (tail == ltemp)
    tail = fence;
  delete ltemp;
  rightcnt--;
  return true;
}

//************************************************************************
// Move fence one step left; no change if left is empty
//************************************************************************
void LList::prev() {
  Link* temp = head;
  if (fence == head) return; // No previous int
  while (temp->next!=fence) temp=temp->next;
  fence = temp;
  leftcnt--; rightcnt++;
}

//************************************************************************
// Set the size of left partition to pos
//************************************************************************
bool LList::setPos(int pos) {
  if ((pos < 0) || (pos > rightcnt+leftcnt)) return false;
  rightcnt = rightcnt + leftcnt - pos; // Set counts
  leftcnt = pos;
  fence = head;
  for(int i=0; i<pos; i++) fence = fence->next;
  return true;
}

//************************************************************************
// Print the contents of the list.
//************************************************************************
void LList::print() const {
  Link* temp = head;				// temp is an iterator variable
  cout << "< ";

  //*************************************************************
  // Note the two while loops: the first one does the left side,
  // i.e. the part of the list before the fence or partition.
  // The second one is on the right side.
  //*************************************************************
  while (temp != fence) {
    cout << temp->next->element << " ";
    temp = temp->next;
  }
  cout << "| ";
  while (temp->next != NULL) {
    cout << temp->next->element << " ";
    temp = temp->next;
  }
  cout << ">\n";
template <class T>

void LList<T>::search ( T & key){
  T it;
  for (setStart (); getValue (it) && it != key ; next() ) {}
}
template <class T>

bool LList<T>::sortedsearch ( constT & key){
  sortedsearch(item);
  return.insert (item);
}

