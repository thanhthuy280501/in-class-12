//************************************************************************
// Singly-linked list node of integer type.
//************************************************************************
#ifndef LINK_H
#define LINK_H

class Link {
  public:
    friend class LList;				// Avoids using accessor and
						// mutator functions with this
    //***************************
    // Two-parameter constructor
    //***************************
    Link(const int elemval, Link* nextval =NULL)
         : element(elemval), next(nextval) { }

    //***********************************
    // Default and one-param constructor
    //***********************************
    Link(Link* nextval =NULL) : next(nextval) { }

  private:
    int element;				// Value for this node
    Link *next;					// Pointer to next node in list
};
#endif
