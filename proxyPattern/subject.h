#pragma once
#include <istream>

// Subject
class Graphic
{
public:
	virtual ~Graphic();

	virtual void Draw(const Point &at) = 0;
	virtual void HandleMouse(Event &event) = 0;
	// Get width, height
	virtual const Point &GetExtent() = 0;

	virtual void Load(std::istream &from) = 0;
	virtual void Save(std::ostream &to) = 0;

protected:
	Graphic();
};

// Real Subject
class Image : public Graphic
{
public:
	explicit Image(const char *file); // loads image from a file
	virtual ~Image();

	void Draw(const Point &at);
	void HandleMouse(Event &event);
	const Point &GetExtent();

	void Load(std::istream &from);
	void Save(std::ostream &to);

private:
	// . . .
};
