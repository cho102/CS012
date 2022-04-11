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
    return *data;
}


const int & IntVector::back() const
{
    
    return *(data + (sz - 1));
}