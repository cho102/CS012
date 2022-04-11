#include <iostream>
#include "IntList.h"

using namespace std;

    IntList::IntList()
    {
        head = nullptr;
        tail = nullptr;
    }

	IntList::~IntList()
    {
        IntNode* first;
        
        for (first = head; first != nullptr; first = head)
        {
            
            head = head->next;
            delete first;
        }
    }

	void IntList::push_front(int num)
    {
        IntNode* temp;
        temp = new IntNode(num);
        temp->next = head;
        head = temp;
        if (tail == nullptr)
        {
            tail = head;
        }
    }

	void IntList::pop_front()
    {
        if (head != nullptr)
        {
            IntNode* temp;
            temp = head->next;
            if (temp == nullptr)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = temp;
            }
        }
        
            
    }

	bool IntList::empty() const
    {
        if (head == nullptr)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

	const int & IntList::front() const
    {
        return head->data;
    }

	const int & IntList::back() const
    {
        return tail->data;
    }

	ostream & operator<<(ostream & out, const IntList & list)
    {
        IntNode* holder = list.head;
        while (holder != nullptr)
        {
            out << holder->data;
            if (holder->next != nullptr)
            {
                out << " ";
            }
            holder = holder->next;
        }
        return out;
    }