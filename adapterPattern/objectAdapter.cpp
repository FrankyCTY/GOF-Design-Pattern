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
class TextShape : public Shape
{
public:
	TextShape(const TextView *);
	virtual void BoundingBox(
			Point &bottomLeft, Point &topRight) const;
	virtual bool IsEmpty() const;
	virtual Manipulator *CreateManipulator() const;

private:
	const TextView *_text;
};

// Constructor initialization hold reference to the adaptee instance
TextShape::TextShape(const TextView *textView)
{
	_text = textView;
}

void TextShape::BoundingBox(
		Point &bottomLeft, Point &topRight) const
{
	Coord bottom, left, width, height;
	// Call adaptee's operations
	_text->GetOrigin(bottom, left);
	_text->GetExtent(width, height);
	bottomLeft = Point(bottom, left);
	topRight = Point(bottom + height, left + width);
}

bool TextShape::IsEmpty() const
{

	// Forward the request to the adpatee
	return _text->IsEmpty();
}

Manipulator *TextShape::CreateManipulator() const
{
	return new TextManipulator(this);
}