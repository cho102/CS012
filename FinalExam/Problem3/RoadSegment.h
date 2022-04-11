#include <string>
#include <vector>
#include "TransportationLink.h"

using namespace std;

#ifndef __ROADSEGMENT_H__
#define __ROADSEGMENT_H__

class RoadSegment : public TransportationLink
{
	private:
		double _speed;
		vector<double> hourlySpeeds;
	
	public:
		RoadSegment(string name, double speed, double distance);
		void setHourSpeed(unsigned hour, double speed);
		void setAllHourSpeeds(const vector<double> &);
		unsigned computeArrivalTime(unsigned minute) const;
};

#endif