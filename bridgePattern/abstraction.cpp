// ============= Refined Abstraction =============#include "common.h"
#include "implementation.h"
#include "./abstraction.h"
#include <iostream>

// ============= Abstraction =============
Window::Window(View *contents)
{
	_imp = GetWindowImp();
}

WindowImp *Window::GetWindowImp()
{
	// if (_imp == 0)
	// {
	// 	// Factory method (static)
	// 	// _imp = WindowSystemFactory::Instance()->MakeWindowImp();
	// }
	return _imp;
}

void Window::DrawRect(const Point &p1, const Point &p2)
{
	_imp->DeviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
}

// ============= Refined Abstraction =============
void ApplicationWindow::DrawContents()
{
	GetView()->DrawOn(this);
}

// ============= Refined Abstraction =============
void IconWindow::DrawContents()
{
	_imp->DeviceBitmap(_bitmapName, Coord(0.0), Coord(0.0));
}
