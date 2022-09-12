#include "./common.h"

Point::Point(int lat, int lnt)
{
	_lat = lat;
	_lng = lnt;
}
Point Point::Zero = Point(0, 0);
Point &Point::operator=(const Point &point)
{
	_lat = point._lat;
	_lng = point._lng;
	// Return the existing object for operator chaining
	return *this;
}
bool Point::operator==(const Point &point)
{
	return point._lat == _lat && point._lng == _lng;
}