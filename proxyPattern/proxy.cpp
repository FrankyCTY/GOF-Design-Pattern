#include <string.h>
#include "./proxy.h"
#include "./common.h"

ImageProxy::ImageProxy(const char *fileName)
{
	// Copy fileName
	_fileName = strdup(fileName);
	_extent = Point::Zero;
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
	if (_extent == Point::Zero)
	{
		_extent = GetImage()->GetExtent();
	}

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