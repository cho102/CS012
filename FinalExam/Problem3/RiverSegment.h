#include <string>
#include <vector>
#include "TransportationLink.h"

using namespace std;

#ifndef __RIVERSEGMENT_H__
#define __RIVERSEGMENT_H__

class RiverSegment : public TransportationLink
{
	private:
		double _speed;
		vector<double> scheduledDepartureTimes;
	
	public: 
		RiverSegment(string name, double speed, double distance);
		void setSpeed(double speed);
		void addDepartureTime(double hour);
		unsigned computeArrivalTime(unsigned minute) const;
	
};

#endif