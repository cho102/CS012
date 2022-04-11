#include <iostream>
#include <vector>
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
            delete head;
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






// IntList(const IntList &cpy): the copy constructor. Make sure this performs deep copy.
    IntList::IntList(const IntList &cpy)
    {
        clear();
//         head = nullptr;
//         tail = head;

        IntNode* temp = cpy.head;
        
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
        
    }


// IntList & operator=(const IntList &rhs): the overloaded assignment operator. Make sure this performs deep copy.
    IntList & IntList::operator=(const IntList &rhs)
    {   
        
        if (this != &rhs)
        {
            if (rhs.head == rhs.tail)
            {
                delete head;
            }
            else
            {
                delete head;
                delete tail;
            }
            
            head = nullptr;
//             new IntNode(rhs.head->data);
            IntNode* temp = rhs.head; 
            while (temp != nullptr)
            {
                push_back(temp->data);
                temp = temp->next;
            }
        }
        
        
        
        return *this;
    }



    void IntList::push_back(int value)
    {
        IntNode* temp;
        temp = new IntNode(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }



    void IntList::clear()
    {
        cout << '1' << endl;
        
        while (head != nullptr)
        {
        cout << '2' << endl;
            
            pop_front();
        }
    }


    void IntList::selection_sort()
    {
        IntNode* first;
        IntNode* second;
        int temp;
        
        for (first = head; first != nullptr; first = first->next)
        {
            for (second = first->next; second != nullptr; second = second->next)
            {
                if (second->data < first->data)
                {
                    temp = first->data;
                    first->data = second->data;
                    second->data = temp;
                }
            }
        }
    }



    void IntList::insert_ordered(int value)
    {
        IntNode* temp = new IntNode(value);
        IntNode* holder;
        holder = head;
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else if (value <= head->data)
        {
            push_front(value);
        }
        else if (value >= tail->data)
        {
            push_back(value);
        }
        else
        {
            while (holder != nullptr)
            {
                if ((value > holder->data) && (value <= holder->next->data))
                {
                    temp->next = holder->next;
                    holder->next = temp;
                }
                holder = holder->next;
            }
        }
    }


    void IntList::remove_duplicates()
    {
        IntNode* first;
        IntNode* second;
        IntNode* temp;
        IntNode* curr;
        if (head != nullptr)
        {
            for (first = head; first != nullptr; first = first->next)
            {
                curr = first;
                for (second = first->next; second != nullptr; second = second->next)
                {   
                    
                    if (first->data == second->data )
                    {
                        if(second->next == nullptr)
                        {
                            curr->next = nullptr;
                            tail = curr;
                        }
                        else
                        {                           
                                temp = second;
                                curr->next = second->next;
                                delete temp;
                        }
                    } else {
                        curr = curr->next;
                    }
                }
            }
        }   
    }