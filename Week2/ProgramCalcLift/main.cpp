#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);


int main(int argc, char* argv[]){
    
    vector <double> angles;
    vector <double> lift;
    string file1;
    double angleIn;
    string cont;
    
    
    file1 = argv[1];    
    readData(file1, angles, lift);
    if (!isOrdered(angles))
    {
        cout << "Not ordered" << endl;
        reorder(angles, lift);
    }
    
    
    cout << "Enter flight path angle: " << endl;
    cin >> angleIn;
    cout << interpolation(angleIn, angles, lift) << endl;
    
    cout << "Continue?" << endl;
    cin >> cont;
    
    if (cont == "Yes")
    {
        cout << "Enter flight path angle: " << endl;
    cin >> angleIn;
    cout << interpolation(angleIn, angles, lift) << endl;
    
    cout << "Continue?" << endl;
    cin >> cont;
        
    }
    
    
    
   for (unsigned int i = 0; i < angles.size(); ++i)
   {
       cout << angles.at(i) << " " << lift.at(i) << endl;
   }
    
        
        
    
    return 0;
}

void readData(const string & file, vector<double> & angles, vector<double> & lift)
{
    double first;
    double second;
    ifstream inFS;
    inFS.open(file);
    
    if (!inFS.is_open())
    {
        cout << "Error opening " << file << endl;
        
        exit(1);
    }
    
    while (inFS >> first)
    {
        angles.push_back(first);
        inFS >> second;
        lift.push_back(second);
    }
    
//     CHECK
    
//     for (unsigned int i = 0; i < angles.size(); ++i)
//     {
//         cout << angles.at(i) << endl;
//     }
    
//     cout << endl;
    
//     for (unsigned int i = 0; i < angles.size(); ++i)
//     {
//         cout << lift.at(i) << endl;
//     }
    
    
    inFS.close();
    
}

// f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

double interpolation(double b, const vector<double> & angles, const vector<double> & lift)
{
    int location;
    double a;
    double c;
    double aLift;
    double bLift;
    double cLift;
    int aLoc;
    int cLoc;
    
    for (unsigned int i = 0; i < angles.size(); ++i)
    {
        if (angles.at(i) == b)
        {
            location = i;
            return lift.at(location);
        }
        else 
        {
            if (b > angles.at(i))
            {
                aLoc = i;
            }
        }  
    }
    cLoc = aLoc + 1;
    a = angles.at(aLoc);
    c = angles.at(cLoc);
    aLift = lift.at(aLoc);
    cLift = lift.at(cLoc);   
    bLift = aLift + (b - a) / (c - a) * (cLift -  aLift);
    return bLift;     
}

bool isOrdered(const vector<double> & angles)
{
    bool ordered = true;
    
    for (unsigned int i = 0; i + 1 < angles.size(); ++i)
    {
        if (angles.at(i) > angles.at(i+1))
        {
            ordered = false;
        }
    }
    
    return ordered;
}

void reorder(vector<double> & angles, vector<double> & lift)
{
    double temp;
    double angleSort;
    double liftSort;
    for (unsigned int i = 0; i < angles.size(); ++i)
    {
    temp = i;
    for (unsigned int j = i + 1; j < angles.size(); ++j)
    {
      if (angles.at(j) < angles.at(temp))
      {
        temp = j;
      }
    }
    angleSort = angles.at(i);
    angles.at(i) = angles.at(temp);
    angles.at(temp) = angleSort;
        
    liftSort = lift.at(i);
    lift.at(i) = lift.at(temp);
    lift.at(temp) = liftSort;
        
        
    }
}

