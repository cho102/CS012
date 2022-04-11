//include any standard libraries needed
#include <iostream>
#include <fstream>
using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
    string fileName = argv[1];
    ifstream inFS;
    inFS.open(fileName);
    double num;
    int input;
    int size = 0;

   // open file and verify it opened
    if (!inFS.is_open())
    {
        cout << "Error opening" << fileName << endl;
    }

   // Declare an array of doubles of size ARR_CAP.
    
    double data[ARR_CAP];

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    
    for (int i = 0; i < ARR_CAP; ++i)
    {
        if (inFS >> num)
        {
            data[i] = num;
            size += 1;
//             cout << size << ". " << num << endl;
        }
    }
    
    inFS.close();
    
//     cout << "Total size: " << size << endl;
    
//     for (int i = 0 ; i < size; ++i)
//     {
//         cout << data[i] << ", ";
//     }
    
   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << mean(data, size) << endl;

   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    
    cout << "Enter index of value to be removed (0 to " << size - 1 << "): " ;
    cin >> input;
    cout << endl;

	
   // Call the display function to output the array.
    cout << "Before removing value: " ;
    display(data, size);
    cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
    
    remove (data, size, input);
  
    
   // Call the display function again to output the array
   // with the value removed.
    cout << "After removing value: " ;
    display(data, size);
    cout << endl;

   
   // Call the mean function again to get the new mean
    
    cout << "Mean: " << mean(data, size) << endl;
   
	return 0;
}


double mean(const double array[], int arraySize)
{
    double sum = 0;
    double avg = 0;
    
    for (int i = 0; i < arraySize; ++i)
    {
        sum += array[i];
    }
    
    avg = sum/arraySize;
    
    return avg;
}


void remove(double array[], int &arraySize, int index)
{
    for (int i = index; i < arraySize - 1; ++i)
    {
        array[i] = array[i+1];
    }
    
    arraySize -= 1;
}



void display(const double array[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; ++i)
    {
        cout << array[i] << ", ";
    }
    cout << array[arraySize - 1];
}