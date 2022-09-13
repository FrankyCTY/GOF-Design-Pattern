#include <iostream>
#include "decorator.h"

// Decorator
Decorator::Decorator(VisualComponent *component)
{
	_component = component;
}

void Decorator::Draw()
{
	// Default to direct forwarding
	_component->Draw();
}

// Concrete Decorator
BorderDecorator::BorderDecorator(VisualComponent *component, int borderWidth) : Decorator(component)
{
	_width = borderWidth;
}

void BorderDecorator::Draw()
{
	_component->Draw();
	DrawBorder(_width);
	std::cout << "Border decorator" << std::endl;
}

void BorderDecorator::DrawBorder(int width)
{
	std::cout << "Drawing border with width " << width << std::endl;
}

// Concrete Decorator
ScrollbarDecorator::ScrollbarDecorator(VisualComponent *component) : Decorator(component)
{
}

void ScrollbarDecorator::Draw()
{
	_component->Draw();
	std::cout << "Scrollbar decorator" << std::endl;
}
