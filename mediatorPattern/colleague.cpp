#include <iostream>
#include "./colleague.h"

// ============= Colleague =============
void Widget::Changed()
{
	_mediator->Notify(this);
}

void Widget::SetMediator(DialogMediator *mediator)
{
	_mediator = mediator;
}

// ============= Concrete Colleague =============
const char *ListBox::GetSelectedItemValue()
{
	return "item value";
}

// ============= Concrete Colleague =============
void TextField::SetText(const char *text)
{
	_text = text;
}

// ============= Concrete Colleague =============
void Button::DoSomething()
{
	std::cout << "Button clicked" << std::endl;
}