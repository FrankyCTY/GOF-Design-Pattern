#pragma once
#include "component.h"

// Decorator
class Decorator : public VisualComponent
{
public:
	explicit Decorator(VisualComponent *);
	Decorator() = default;
	void Draw();

protected:
	VisualComponent *_component;
};

// Concrete Decorator
class BorderDecorator : public Decorator
{
public:
	explicit BorderDecorator(VisualComponent *, int borderWidth);
	void Draw();

private:
	void DrawBorder(int);

private:
	int _width;
};

class ScrollbarDecorator : public Decorator
{
public:
	ScrollbarDecorator(VisualComponent *);
	void Draw();
};
