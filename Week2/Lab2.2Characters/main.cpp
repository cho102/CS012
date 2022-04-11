#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string& file, char c);

int main() {
   string filename;
   char ch;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;
   if (charCnt(filename, ch) == -1)
   {
        cout << "Error opening " << filename << endl;
   }
   else
   {
        cout << "# of " << ch << "'s: " << charCnt(filename, ch) << endl;
   }
   
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string& file, char c){
    int count = 0;
    char x;
    ifstream inFS;
    
    inFS.open(file);
    if(!inFS.is_open())
    {
       return -1;
    }
    else {
        while (!inFS.eof())
        {
            inFS.get(x);
            if (!inFS.fail())
            {
                if (x == c)
                {
                    count += 1;
                }
            }
            
        }
    }
    inFS.close();
    return count;
}