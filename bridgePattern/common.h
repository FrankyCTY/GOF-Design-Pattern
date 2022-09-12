#pragma once

class Coord
{
public:
	Coord(double coord);
};

class Point
{
public:
	static Coord X();
	static Coord Y();

private:
	static Coord x;
	static Coord y;
};

Coord Point::X()
{
	return x;
}

Coord Point::Y()
{
	return y;
}

class Display
{
};

class Drawable
{
};

class GC
{
};

class HPS
{
};