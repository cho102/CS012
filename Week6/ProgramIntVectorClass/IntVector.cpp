#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector()
{
    sz = 0;
    cap = 0;

    data = new int[sz];
}


IntVector::IntVector(unsigned size, int value)
{
    sz = size;
    cap = size;
    
    data = new int[size];
    for (unsigned int i = 0; i < sz; ++i)
    {
        data[i] = value;
    }
    
    
//     *data = new arr[size]
        
}


IntVector::~IntVector()
{
    delete[] data;
}


unsigned IntVector::size() const
{
    return sz;
}

    
unsigned IntVector::capacity() const
{
    return cap;
}


bool IntVector::empty() const
{
    if (sz == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


const int & IntVector::at(unsigned index) const
{
    if (index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return *(data + index);
    }
}


const int & IntVector::front() const
{
    return *(data + 0);
}


const int & IntVector::back() const
{
    
    return *(data + (sz - 1));
}

//PROGRAM


int & IntVector::at(unsigned index)
{
    if (index >= sz)
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return *(data + index);
    }
}

int & IntVector::front()
{
    return *data;
}
        
int & IntVector::back()
{
    return *(data + (sz - 1));
}

void IntVector::insert(unsigned index, int value)
{
    if (index > sz)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if ((sz + 1) > cap)
    {
        expand();
    }
    
    sz += 1;
    
    for (unsigned int i = sz - 1; i > index ; --i)
    {
        *(data + i) = *(data + (i - 1));
    }
    
    *(data + index) = value;
}
        
void IntVector::erase(unsigned index)
{
    if (index >= sz)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index; i < sz; ++i)
    {
        data[i] = data[i + 1];
    }
    
    sz -= 1;
}
        
      
void IntVector::assign(unsigned n, int value)
{
    if (n > cap)
    {
        if ((cap * 2) > (n))
        {
            expand();
        }
        else 
        {
            expand(n - cap);
        }
       
    }
    
    sz = n;
    for (unsigned int i = 0; i < sz; ++i)
    {
        data[i] = value;
    }
}
        
void IntVector::push_back(int value)
{
    if ((sz + 1) > cap )
    {
        expand();
    }
    *(data + sz) = value;
    sz += 1;
}
        
void IntVector::pop_back()
{
    sz -= 1;
}
        
void IntVector::clear()
{
    sz = 0;
}
        
void IntVector::resize(unsigned size, int value)
{
    if (size > cap)
    {
        if ((cap * 2) > (size))
        {
            expand();
        }
        else 
        {
            expand(size - cap);
        }
       
    }
    
    for (unsigned int i = sz; i < size; ++i)
    {
        *(data + i) = value;
    }
    sz = size;
}
        
void IntVector::reserve(unsigned n)
{
        if (n > cap)
        {
            cap = n;
        }

}


void IntVector::expand()
{
    if (cap == 0)
    {
        cap = 1;
    }
    else
    {
        cap = 2 * cap;
    }
    
    
    int* temp = nullptr;
    temp = new int[cap];
    
    for (unsigned int i = 0; i < sz; ++i)
    {
        temp[i] = data[i];
    }
    
    delete[] data;
    
    data = temp;
}
        
void IntVector::expand(unsigned amount)
{
    cap += amount;
    int* temp = nullptr;
    temp = new int[cap];
    
    for (unsigned int i = 0; i < sz; ++i)
    {
        temp[i] = data[i];
    }
    
    delete[] data;
    
    data = temp;
    
}
    