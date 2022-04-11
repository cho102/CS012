#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    ifstream inFS;
    int i = 0;
    string s;
    
    if (argc != 2)
    {
        return 1;
    }
    
    inFS.open(argv[1]);
    
    while (!inFS.eof())
    {
        inFS >> i;
        if (inFS.fail())
        {
            inFS.clear();
            inFS >> s;
            if (inFS.eof())
            {
                return 1;
            }
            cout << s << "is not a number, cannot be squared" << endl;
        }
        else 
        {
            cout << i * i << endl;
        }
    }
    
    
    
    
    
// //     CHECK AGE FOR DRIVING
//     int age = 0;
    
//     while (inFS >> age)
//     {
//         if (argv[1] < 16)
//         {
//             cout << "Age " << age << ": Too Young to Drive" << endl;
//         }
//         else 
//         {
//             cout << "Age " << age << ": Can Drive" << endl;
//         }
//     }
    inFS.close();
    
    return 0;
}