#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

int main()
{
    
    //test default constructor
     IntVector vect;
    
    
    //test custom constructor
    
    //IntVector vect(3, 5);
    
    //test .empty();

    //cout << "testing: " << vect.empty() << endl;
    
    //test .capacity();
    
    cout << "capacity: " << vect.capacity() << endl;
    
    //test .at();
    
    //cout << "at: " << vect.at(6) << endl;
    
    
    //test .front();
    
    cout << "front: " << vect.front() << endl;
    
    
    //test .back();
    
    cout << "back: " << vect.back() << endl;
    
    
    //test .size();
    
    cout << "size: " << vect.size() << endl;
    
    
    return 0;
}