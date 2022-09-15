#pragma once
#include "./mediator.h"

// ============= Colleague =============
class Widget
{
public:
	Widget();
	void Changed();
	void SetMediator(DialogMediator *mediator);

protected:
	DialogMediator *_mediator;
};

// ============= Concrete Mediator =============
class ListBox : public Widget
{
public:
	ListBox();
	const char *GetSelectedItemValue();
};

// ============= Concrete Mediator =============
class TextField : public Widget
{
public:
	TextField();
	void SetText(const char *text);

private:
	const char *_text;
};

// ============= Concrete Mediator =============
class Button : public Widget
{
public:
	Button();
	void DoSomething();
};