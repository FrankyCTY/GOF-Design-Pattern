#pragma once

class Event
{
};

class Point
{
public:
	explicit Point(int lat, int lng);
	Point();
	static Point Zero;

	Point &operator=(const Point &point);
	bool operator==(const Point &point);

private:
	int _lat;
	int _lng;
};
