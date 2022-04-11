#include "RiverSegment.h"
#include <iostream>
#include <vector>

using namespace std;

RiverSegment::RiverSegment(string name, double speed, double distance) : TransportationLink(name, distance), _speed(speed){};

void RiverSegment::setSpeed(double speed)
{
	_speed = speed;
}
		
void RiverSegment::addDepartureTime(double hour)
{
	double temp;
	double temp1;
	scheduledDepartureTimes.push_back(hour);
	
	for (unsigned int i = 0; i < scheduledDepartureTimes.size(); ++i)
	  {
		temp = i;
		for (unsigned int j = i + 1; j < scheduledDepartureTimes.size(); ++j)
		{
		  if (scheduledDepartureTimes.at(j) < scheduledDepartureTimes.at(temp))
		  {
			temp = j;
		  }
		}
		temp1 = scheduledDepartureTimes.at(i);
		scheduledDepartureTimes.at(i) = scheduledDepartureTimes.at(temp);
		scheduledDepartureTimes.at(temp) = temp1;
	  }
	
}
		
unsigned RiverSegment::computeArrivalTime(unsigned minute) const
{
	double nextTime;
	unsigned int loc;
	
// 	double convertedMin = static_cast<double>(minute) / 60;

   if (scheduledDepartureTimes.at(0) * 60 > minute)
   {
      nextTime = scheduledDepartureTimes.at(0);
   }
   else if (scheduledDepartureTimes.at(scheduledDepartureTimes.size() - 1) * 60 == minute)
   {
      nextTime = scheduledDepartureTimes.at(scheduledDepartureTimes.size() - 1);
   }
   else
   {
      for (unsigned int i = 0; i < scheduledDepartureTimes.size(); ++i)
   	{
   		if (scheduledDepartureTimes.at(i) * 60 < minute)
   		{
   			loc = i;
   		}
   	}
   	
   	if((loc + 1) == scheduledDepartureTimes.size())
   	{
   		nextTime = scheduledDepartureTimes.at(0) + 24;
   	}
   	else
   	{
   		nextTime = scheduledDepartureTimes.at(loc + 1);
   	}
   }
	
	
	
	double diff = nextTime * 60;
	double length = (_distance / _speed) * 60 ;
	double num = length + diff;
	return num;
}