#pragma once
#include "./common.h"
#include "./implementation.h"

class View
{
public:
	void DrawOn(Window *w);
};

// ============= Abstraction =============
class Window
{
public:
	explicit Window(View *contents);
	// requests handled by window
	virtual void DrawContents() = 0;

	// requests forwarded to implementation
	virtual void DrawRect(const Point &, const Point &) = 0;

protected:
	// Implementation is hidden from client
	WindowImp *GetWindowImp();
	View *GetView();

protected:
	WindowImp *_imp;
	View *_contents;
};

// ============= Refined Abstraction =============
class ApplicationWindow : public Window
{
public:
	void DrawContents();
};

// ============= Refined Abstraction =============
class IconWindow : public Window
{
public:
	void DrawContents();

private:
	const char *_bitmapName;
};