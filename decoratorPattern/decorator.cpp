#include "decorator.h"

void Decorator::Draw()
{
	_component->Draw();
}
void Decorator::Resize()
{
	_component->Resize();
}

void BorderDecorator::Draw()
{
	Decorator::Draw();
	DrawBorder(_width);
}
