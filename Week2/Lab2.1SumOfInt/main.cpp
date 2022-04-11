#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
 int fileSum (const string& file);

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
    
    if (fileSum(filename) == 1)
    {
        cout << "Error opening " << filename << endl;
    }
    else
    {
        cout << "Sum: " << fileSum(filename) << endl;
    }
   

   return 0;
}

// Place fileSum implementation here
int fileSum (const string& file){
    ifstream inFS;
    int sum = 0;
    int x;
    
    inFS.open(file);
    if(!inFS.is_open()){
        return 1;
    }
    else {
        while (!inFS.eof()){
            inFS >> x;
            if (!inFS.fail()){
                sum += x;
            }
        }
        inFS.close();
        return sum;
    }      

}