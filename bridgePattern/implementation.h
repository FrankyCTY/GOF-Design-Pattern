#include "common.h"
#include <iostream>

// Implementation
class WindowImp
{
public:
	virtual void ImpTop() = 0;
	virtual void ImpBottom() = 0;
	virtual void ImpSetExtent(const Point &) = 0;
	virtual void ImpSetOrigin(const Point &) = 0;
	virtual void DeviceRect(Coord, Coord, Coord, Coord) = 0;
	virtual void DeviceText(const char *, Coord, Coord) = 0;
	virtual void DeviceBitmap(const char *, Coord, Coord) = 0;
	// ...
protected:
	WindowImp();
};

// Concrete Implementation
class XWindowImp : public WindowImp
{
public:
	XWindowImp();

	virtual void DeviceRect(Coord, Coord, Coord, Coord);
	// ...
private:
	Display *_dpy;
	Drawable _windowId;
	GC _gc;
};

// Concrete Implementation
class PMWindowImp : public WindowImp
{
public:
	PMWindowImp();
	virtual void DeviceRect(Coord, Coord, Coord, Coord);
	// ...
private:
	HPS _hps;
};
