#include <iostream>
#include "./common.h"

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
	virtual bool IsEmpty() const;
	virtual void OtherMethod() const;
};

// =============== Adapter ===============
class TextShape : public Shape
{
public:
	explicit TextShape(const TextView *);
	void BoundingBox(
			Point &bottomLeft, Point &topRight) const;
	bool IsEmpty() const;
	void OtherMethod() const;

private:
	const TextView *_text;
};

TextShape::TextShape(const TextView *textView)
{
	_text = textView;
}

// Convert TextView's interface to conform to Shape's interface
void TextShape::BoundingBox(
		Point &bottomLeft, Point &topRight) const
{
	Coord bottom, left, width, height;
	_text->GetOrigin(bottom, left);
	// ...
}

bool TextShape::IsEmpty() const
{

	// Forward the request to the adpatee
	return _text->IsEmpty();
}

void TextShape::OtherMethod() const
{
	std::cout << "Method that not supported by adaptee" << std::endl;
}