#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream & out, const IntList & n)
{
    if (n.head == nullptr)
    {
        return out;
    }
    out << n.head->data;
    IntList temp = n;
    temp.head = n.head->next;
    if (temp.head != nullptr)
    {
        out << " ";
    }
    out << temp;
    
    return out;
    
}


// ostream & operator<<(ostream &, IntNode *)
// {
    
// }


bool IntList::exists(int n) const
{
    if (head == nullptr)
    {
        return false;
    }
    
    return exists(head, n);
}

bool IntList::exists(IntNode * i, int n) const
{
    if (i->data == n)
    {
        return true;
    }
    if (i->next == nullptr)
    {
        return false;
    }
    return exists(i->next, n);
}