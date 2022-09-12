#include "common.h"
#include "implementation.h"
#include <iostream>

class View
{
public:
	void DrawOn(Window *w);
};

// Abstraction
class Window
{
public:
	Window(View *contents);
	// requests handled by window
	virtual void DrawContents();
	virtual void Open();
	virtual void Close();
	virtual void Iconify();
	virtual void Deiconify();

	// requests forwarded to implementation
	virtual void SetOrigin(const Point &at);
	virtual void SetExtent(const Point &extent);
	virtual void Raise();
	virtual void Lower();

	virtual void DrawLine(const Point &, const Point &);
	virtual void DrawRect(const Point &, const Point &);
	virtual void DrawPolygon(const Point[], int n);
	virtual void DrawText(const char *, const Point &);

protected:
	// Implementation is hidden from client
	WindowImp *GetWindowImp();
	View *GetView();

private:
	WindowImp *_imp;
	View *_contents;
};

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
	WindowImp *imp = GetWindowImp();
	imp->DeviceRect(p1.X(), p1.Y(), p2.X(), p2.Y());
}

class ApplicationWindow : public Window
{
public:
	// . . .
	virtual void DrawContents();
};

// Refined Abstraction
void ApplicationWindow::DrawContents()
{
	GetView()->DrawOn(this);
}

class IconWindow : public Window
{
public:
	// ...
	virtual void DrawContents();

private:
	const char *_bitmapName;
};

// Refined Abstraction
void IconWindow::DrawContents()
{
	WindowImp *imp = GetWindowImp();
	if (imp != 0)
	{
		imp->DeviceBitmap(_bitmapName, 0.0, 0.0);
	}
}
