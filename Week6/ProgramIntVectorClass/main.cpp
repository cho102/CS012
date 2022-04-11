#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

int main()
{
    cout << "TESTING IntVector vect(3, 5)" << endl;
    cout << "Should Show: 5 5 5 " << endl;
    IntVector vect(3, 5);
    
    cout << "Show Vector: ";
    for (int i = 0; i < 3; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "Constructor Testing done." << endl << endl;
    
    
    //test push_back
    cout << "TESTING vect.push_back(4)" << endl;
    cout << "Should Show: 5 5 5 4 " << endl;
    vect.push_back(4);
    
    cout << "Show Vector:" << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "PUSH_BACK Testing done." << endl << endl;
    
    
    //test insert
    cout << "TESTING vect.insert(2,3)" << endl;
    cout << "Should Show: 5 5 3 5 4 " << endl;
    vect.insert(2,3);
    
    cout << "Show Vector: ";
    for (int i = 0; i < 5; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "INSERT Testing done." << endl << endl;
    
    cout << "TESTING vect.insert(0,3)" << endl;
    cout << "Should Show: 3 5 5 3 5 4 " << endl;
    vect.insert(0,3);
    cout << "Show Vector: ";
    for (int i = 0; i < 6; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "INSERT Testing done." << endl << endl;
    
    
    cout << "TESTING vect.insert(5,3)" << endl;
    cout << "Should Show: 3 5 5 3 5 3 4 " << endl;
    vect.insert(5,3);
    cout << "Show Vector: ";
    for (int i = 0; i < 7; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "INSERT Testing done." << endl << endl;
    
    cout << "TESTING vect.insert(7,3)" << endl;
    vect.insert(7,3);
    
    
    return 0;
    
    //test front and back
    cout << "TESTING vect.front() and vect.back()" << endl;
    cout << "Should Show: 5 4 " << endl;
    vect.front();
    vect.back();
    cout << "Show Vector: " << vect.front() << " " <<  vect.back() << endl;
    cout << "FRONT and BACK Testing done" << endl << endl;
    
    
    //test erase
    cout << "TESTING vect.erase(0)" << endl;
    cout << "Should Show: 5 3 5 4 " << endl;
    vect.erase(0);
    
    cout << "Show Vector: ";
    for (int i = 0; i < 4; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "ERASE Testing done." << endl << endl;
    
    //test resize()
    
    cout << "TESTING vect.resize(7, 8)" << endl;
    cout << "Should Show: 5 3 5 4 8 8 8 " << endl;
    vect.resize(7, 8);
    
    cout << "Show Vector: ";
    for (int i = 0; i < 7; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "RESIZE Testing done." << endl << endl;
    
    
    //test pop_back()
    cout << "TESTING vect.pop_back()" << endl;
    cout << "Should Show: 5 3 5 4 8 8 " << endl;
    vect.pop_back();
    
    cout << "Show Vector: ";
    for (int i = 0; i < 6; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "POP_BACK Testing done." << endl << endl;
    
    
    //test at
    cout << "TESTING vect.at(2) = 9" << endl;
    cout << "Should Show: 5 3 9 4 8 8 " << endl;
    vect.at(2) = 9;
    
    cout << "Show Vector: ";
    for (int i = 0; i < 6; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "AT Testing done." << endl << endl;
    
    
    //test assign
    cout << "TESTING vect.assign(8, 3)" << endl;
    cout << "Should Show: 3 3 3 3 3 3 3 3 " << endl;
    vect.assign(10, 3);
    
    cout << "Show Vector: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << vect.at(i) << " ";
    }
    cout << endl;
    cout << "ASSIGN Testing done." << endl << endl;
    
    //test empty
    cout << "TESTING vect.empty()" << endl;
    cout << "Should Show: 0" << endl;
    vect.empty();
    cout << "Show Vector: " << vect.empty() << endl;
    cout << "EMPTY Testing done." << endl << endl;
    
    //test clear
    cout << "TESTING vect.clear()" << endl;
    cout << "Should Show: size: 0 empty: 1" << endl;
    vect.clear();
    cout << "Show Vector: size: " << vect.size() << " empty: " << vect.empty() << endl;
    cout << "CLEAR Testing done." << endl << endl;
    
    
    
    
    return 0;
}