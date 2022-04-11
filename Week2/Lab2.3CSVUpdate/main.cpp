#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   int inNum = 0;
   int sum = 0; 
   vector<int> v; 
   char c = ',';
   int avg = 0;
    
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
    
   // Create input stream and open input csv file.
    ifstream inFS;
    inFS.open(inputFile);
    
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open())
   {
       cout << "Error opening" << "inputFile" << endl;
       return -1;
   }
    
   // Read in integers from input file to vector.
    
    while (inFS >> inNum)
       {
           v.push_back(inNum);
           inFS >> c;
       }
    
    
   // Close input stream.
   inFS.close();
    
   // check 
//    for (unsigned int i = 0 ; i < v.size(); ++i)
//    {
//        cout << v.at(i) << endl;
//    }
    
    
   // Get integer average of all values read in.
   for (unsigned int i = 0; i < v.size(); ++i)
   {
       sum += v.at(i);
   }
    
   avg = sum / v.size();
    
   
    
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < v.size(); ++i)
   {
       v.at(i) = v.at(i) - avg;
   }
   
   //Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
    

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open())
   {
       cout << "Error opening" << "outputFile" << endl;
       return -1;
   }
    
    
    
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < v.size()-1; ++i)
   {
       outFS << v.at(i) << "," ;
   }
   outFS << v.at(v.size()-1); 
    
    
   // Close output stream.
   outFS.close();
   
   return 0;
}