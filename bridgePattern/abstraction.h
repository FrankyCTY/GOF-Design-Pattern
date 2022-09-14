#pragma once
#include "./implementation.h"

// ============= Abstraction =============
class Window
{
public:
	explicit Window();
	// requests handled by abstraction
	virtual void DrawContents() = 0;

	// requests forwarded to implementation
	void DrawRect();

protected:
	WindowImp *_imp;
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
};