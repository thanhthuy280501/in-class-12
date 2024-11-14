#ifndef LLIST_H
#define LLIST_H
#define DefaultListSize 50

//************************************************************************
// Integer Linked list implementation
//
// This example contains many inline functions.
//************************************************************************
class LList {
  private:
    Link* head;				// Pointer to list header
    Link* tail;				// Pointer to last int in list 
    Link* fence;			// Last element on left side
    int leftcnt;            		// Size of left partition
    int rightcnt;			// Size of right partition

    // Private routines:

    //**************************************************************
    // Initialization routine.  Create a dummy Link node and set
    // all the list pointers to point at it.
    // note that it's inline.
    //**************************************************************
    void init() {
      fence = tail = head = new Link;
      leftcnt = rightcnt = 0;
    }

    void removeall();			// Removes all elements of the list.

  public:

    //**************************************************************
    // To construct, simply call the init helper routine.
    //**************************************************************
    LList(int size=DefaultListSize) { init(); }

    //**************************************************************
    // To destruct, simply call the removeall helper routine.
    //**************************************************************
    ~LList() { removeall(); }  // Destructor

    //**************************************************************
    // Remove all elements from the list.  Use the helper routines
    // to do that.
    //**************************************************************
    void clear() { removeall(); init(); }

    //**************************************************************
    // Move the fence all the way to the left.
    //**************************************************************
    void setStart()
      { fence = head; rightcnt += leftcnt; leftcnt = 0; }

    //**************************************************************
    // Move the fence all the way to the right
    //**************************************************************
    void setEnd()
      { fence = tail; leftcnt += rightcnt; rightcnt = 0; }

    //**************************************************************
    // Move the fence one position right.
    //**************************************************************
    void next() {
      if (fence != tail) // Don't move fence if right empty
        { fence = fence->next; rightcnt--; leftcnt++; }
    }

    //**************************************************************
    // Move the fence one position left (why do you suppose this
    // one is not inline?)
    //**************************************************************
    void prev();

    //**************************************************************
    // Report the left and right lengths.
    //**************************************************************
    int leftLength() const  { return leftcnt; }
    int rightLength() const { return rightcnt; }

    bool setPos(int pos);		// Set position to random location

    //**************************************************************
    // Return the value stored at current fence position.
    //**************************************************************
    bool getValue(int& it) const {
      if(rightLength() == 0) return false;
      it = fence->next->element;
      return true;
    }

    // Non-inline functions:

    bool insert(const int);		// insert an element at current fence location
    bool append(const int);		// append an element to the list.
    bool remove(int&);			// remove an element from current fence location
    void print() const;			// Print the list.
};

#endif
