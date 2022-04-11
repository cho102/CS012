#include "RoadSegment.h"

using namespace std;

RoadSegment::RoadSegment(string name, double speed, double distance) : TransportationLink(name, distance), _speed(speed)
{
	hourlySpeeds.resize(24);
	for (unsigned int i = 0; i < hourlySpeeds.size(); ++i)
	{
	     hourlySpeeds.at(i) = _speed;
	}
}

void RoadSegment::setHourSpeed(unsigned hour, double speed)
{
	hourlySpeeds.at(hour) = speed;
}

void RoadSegment::setAllHourSpeeds(const vector<double> &v)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		hourlySpeeds.at(i) = v.at(i);
	}
}

unsigned RoadSegment::computeArrivalTime(unsigned minute) const
{
	unsigned num;
	unsigned int hour;
	double length;
	hour = minute / 60;
	
// 	length = _distance / _speed;
	length = (_distance / hourlySpeeds.at(hour)) * 60;
	num = minute + length;
	return num;
}