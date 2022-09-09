#include <iostream>

class Point
{
public:
	Point(int lat, int lng);
	static Point Zero;
	int getLat() const
	{
		return _lat;
	}

private:
	int _lat;
	int _lng;
};

Point::Point(int lat, int lnt)
{
	_lat = lat;
	_lng = lnt;
}
Point Point::Zero = Point(0, 0);

void display(const Point &point)
{
	std::cout << "asd " << point.getLat() << std::endl;
}

int add10(int a)
{
	a = 2;
	std::cout << "parameter a is " << a << std::endl;
	return a + 10;
}

int main()
{
	display(Point::Zero);
	// int input = 5;
	// int result = add10(input);
	// std::cout << "result is " << result << std::endl;
	// std::cout << "input is " << input << std::endl;
	return 0;
}