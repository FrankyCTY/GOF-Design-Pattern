#include <iostream>
#include <string.h>

class Event
{
};

class Point
{
public:
	Point();
	static Point *Zero;
};

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
	Image(const char *file); // loads image from a file
	virtual ~Image();

	virtual void Draw(const Point &at);
	virtual void HandleMouse(Event &event);
	virtual const Point &GetExtent();

	virtual void Load(std::istream &from);
	virtual void Save(std::ostream &to);

private:
	// . . .
};

// Proxy
class ImageProxy : public Graphic
{
public:
	ImageProxy(const char *imageFile);
	virtual ~ImageProxy();

	virtual void Draw(const Point &at);
	virtual void HandleMouse(Event &event);
	virtual const Point &GetExtent();

	virtual void Load(std::istream &from);
	virtual void Save(std::ostream &to);

protected:
	Image *GetImage();

private:
	Image *_image;
	Point _extent;
	char *_fileName;
};

ImageProxy::ImageProxy(const char *fileName)
{
	// Copy fileName
	_fileName = strdup(fileName);
	_extent = Point();
	_image = 0;
}

// Control access to create object - Use cached image if exist
Image *ImageProxy::GetImage()
{
	if (_image == 0)
	{
		_image - new Image(_fileName);
	}
	return _image;
}

const Point &ImageProxy::GetExtent()
{
	// if extent is not set
	_extent = GetImage()->GetExtent();

	// otherwise return cached extent
	return _extent;
}

void ImageProxy::Draw(const Point &at)
{
	GetImage()->Draw(at);
}

void ImageProxy::HandleMouse(Event &event)
{
	GetImage()->HandleMouse(event);
}