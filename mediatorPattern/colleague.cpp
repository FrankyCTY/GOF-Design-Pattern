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
	std::cout << "Getting selected item value from list box" << std::endl;
	return "selected item value";
}

// ============= Concrete Colleague =============
void TextField::SetText(const char *text)
{
	std::cout << "Setting the text for the text field" << std::endl;
	_text = text;
}

// ============= Concrete Colleague =============
void Button::DoSomething()
{
	std::cout << "Button clicked" << std::endl;
}