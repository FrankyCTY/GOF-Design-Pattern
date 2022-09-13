#include <iostream>
#include "./common.h"
// This code example is not complete, don't learn C++ from this

// =============== Adaptee ===============
class TextView
{
public:
	explicit TextView();
	void GetOrigin(Coord &x, Coord &y) const;
	virtual bool IsEmpty() const;
};

// =============== Target ===============
class Shape
{
public:
	explicit Shape();
	virtual void BoundingBox(
			Point &bottomLeft, Point &topRight) const;
	virtual void OtherMethod() const;
};

// =============== Adapter ===============
class TextShape : public Shape, private TextView
{
public:
	explicit TextShape();
	void BoundingBox(
			Point &bottomLeft, Point &topRight) const;
	bool IsEmpty() const;
	void OtherMethod() const;
};

// Convert TextView's interface to conform to Shape's interface
void TextShape::BoundingBox(
		Point &bottomLeft, Point &topRight) const
{
	Coord bottom, left, width, height;
	GetOrigin(bottom, left);
	// ...
};

// Forward the request to the adpatee
bool TextShape::IsEmpty() const
{
	return TextView::IsEmpty();
}

void TextShape::OtherMethod() const
{
	std::cout << "Method that not supported by adaptee" << std::endl;
}