#include "./colleague.h"
#include "./mediator.h"

int main()
{
	ListBox *listBox = new ListBox();
	TextField *textField = new TextField();
	Button *submitButton = new Button();

	FontDialogMediator *fontDialogMediator = new FontDialogMediator(listBox, textField, submitButton);

	listBox->Changed();			 // Will then Set text in text field
	submitButton->Changed(); // Will then set font and close dialog

	return 0;
}