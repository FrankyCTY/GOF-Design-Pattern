#pragma once
#include "component.h"

// Decorator
class Decorator : public VisualComponent
{
public:
	Decorator(VisualComponent *);
	virtual void Draw();
	virtual void Resize();
	// . . -
private:
	VisualComponent *_component;
};

// Concrete Decorator
class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent *, int borderWidth);
	virtual void Draw();

private:
	void DrawBorder(int);

private:
	int _width;
};
