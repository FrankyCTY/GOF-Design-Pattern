#include "./mediator.h"

// ============= Concrete Mediator =============
FontDialogMediator::FontDialogMediator(ListBox *listBox, TextField *textField, Button *button)
{
	_listBox = listBox;
	_textField = textField;
	_submitButton = button;

	_listBox->SetMediator(this);
	_textField->SetMediator(this);
	_submitButton->SetMediator(this);
}

void FontDialogMediator::Notify(Widget *changedWidget)
{
	if (changedWidget == _listBox)
	{
		const char *selectedListItemValue = _listBox->GetSelectedItemValue();
		_textField->SetText(selectedListItemValue);
	}
	else if (changedWidget == _submitButton)
	{
		// Apply font change and dismiss dialog
	}
}
