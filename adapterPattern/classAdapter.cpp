// This code example is not complete, don't learn C++ from this
class Point
{
public:
	Point(Coord lon, Coord lat);
};

// Can animate a shape when user manipulates it
class Manipulator
{
};

class TextManipulator : public Manipulator
{
public:
	TextManipulator(const TextShape *);
};

class Coord
{
	friend Coord operator+(Coord &a, Coord &b)
	{
		return a + b;
	}
};

// Adaptee
class TextView
{
public:
	TextView();
	void GetOrigin(Coord &x, Coord &y) const;
	void GetExtent(Coord &width, Coord &height) const;
	virtual bool IsEmpty() const;
};

// Target
class Shape
{
public:
	Shape();
	virtual void BoundingBox(
			Point &bottomLeft, Point &topRight) const;

	virtual Manipulator *CreateManipulator() const;
};

// Adapter
class TextShape : public Shape, private TextView
{
public:
	TextShape();
	virtual void BoundingBox(
			Point &bottomLeft, Point &topRight) const;
	virtual bool IsEmpty() const;
	virtual Manipulator *CreateManipulator() const;
};

// Convert TextView's interface to conform to Shape's
void TextShape::BoundingBox(
		Point &bottomLeft, Point &topRight) const
{
	Coord bottom, left, width, height;
	GetOrigin(bottom, left);
	GetExtent(width, height);
	bottomLeft = Point(bottom, left);
	topRight = Point(bottom + height, left + width);
};

// Forward the request to the adpatee
bool TextShape::IsEmpty() const
{
	return TextView::IsEmpty();
}

Manipulator *TextShape::CreateManipulator() const
{
	return new TextManipulator(this);
}