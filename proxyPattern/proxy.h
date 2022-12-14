#pragma once
#include "./subject.h"
#include "./common.h"

// Use subject's interface
class ImageProxy : public Graphic
{
public:
	explicit ImageProxy(const char *imageFile);
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
	// Keep soft reference (not actual object) to file
	char *_fileName;
};