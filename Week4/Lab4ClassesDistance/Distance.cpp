#include <iostream>
using namespace std;

#include "Distance.h"


Distance::Distance()
{
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double in)
{
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in)
{
    feet = 0;
    inches = in;
    init();
    
}

unsigned Distance::getFeet() const
{
    return feet;
}

double Distance::getInches() const
{
    return inches;
}

double Distance::distanceInInches() const
{
    double totIn;
    totIn = inches + (feet * 12);
    return totIn;
}

double Distance::distanceInFeet() const
{
    double feetDistance;
    feetDistance = feet + (inches/12);
    return feetDistance;
}

double Distance::distanceInMeters() const
{
    double meter;
    double ftToIn;
    double total;

    ftToIn = feet * 12;
    total = ftToIn + inches;
    
    
    meter = total * 0.0254;
    
    return meter;
}

Distance Distance::operator+(const Distance &rhs) const
{
    Distance total;
    
    total.feet = feet + rhs.feet;
    total.inches = inches + rhs.inches;
    
    while (total.inches >= 12)
    {
        total.feet += 1;
        total.inches -= 12;
    }
    
    return total;
}

Distance Distance::operator-(const Distance &rhs) const
{
    Distance total;
    double first;
    double second;
    double fin;
    int ft;
    
    first = distanceInInches();
    second = rhs.distanceInInches();
    
    if (first > second)
    {
        fin = first - second;
    }
    else
    {
        fin = second - first;
    }
    
    ft = fin / 12;
    
    total.feet = ft;
    total.inches = fin - (ft * 12);
    
    return total;
}

void Distance::init()
{
    if (inches < 0)
    {
        inches = inches * -1;
    }
    while (inches >= 12.0)
    {
        feet += 1;
        inches -= 12.0;
    }
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}
