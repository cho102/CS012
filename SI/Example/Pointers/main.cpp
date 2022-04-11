#include <iostream>

using namespace std;


int main()
{
    
   //int arr[5];
    int* pntr;
    pntr = new int[5];
    
    for (int i = 0; i < 5 ; ++i)
    {
        pntr[i] = i;
    }
    
    cout << "pntr: " << pntr << endl;
    cout << "*pntr: " << *pntr << endl;
    cout << "*pntr + 1: " << *(pntr + 1) << endl;
    
    
    
    
    
    
    return 0;
}
    
