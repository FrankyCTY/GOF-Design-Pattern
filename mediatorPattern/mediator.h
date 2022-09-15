#pragma once
#include "./colleague.h"

// ============= Mediator =============
class DialogMediator
{
public:
	virtual ~DialogMediator();
	virtual void Notify(Widget *) = 0;

protected:
	DialogMediator();
};

// ============= Mediator =============
class FontDialogMediator : public DialogMediator
{
public:
	FontDialogMediator(ListBox *listBox, TextField *textField, Button *button);
	virtual ~FontDialogMediator();
	void Notify(Widget *);

private:
	ListBox *_listBox;
	TextField *_textField;
	Button *_submitButton;
};