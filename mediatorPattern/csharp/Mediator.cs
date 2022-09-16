abstract class DialogMediator
{
	public abstract void Notify(Widget widget);
}

class FontDialogMediator : DialogMediator
{
	private ListBox _listBox;
	private TextField _textField;
	private Button _submitButton;

	public FontDialogMediator(ListBox listBox, TextField textField, Button submitButton)
	{
		_listBox = listBox;
		_textField = textField;
		_submitButton = submitButton;

		listBox.SetMediator(this);
		textField.SetMediator(this);
		submitButton.SetMediator(this);
	}

	public override void Notify(Widget changedWidget)
	{
		System.Console.WriteLine("============ NOTIFY ============");

		if (changedWidget == _listBox)
		{
			string selectedListItemValue = _listBox.GetSelectedItemValue();
			_textField.SetText(selectedListItemValue);
		}
		else if (changedWidget == _submitButton)
		{
			// Apply font change and dismiss dialog
			_submitButton.DoSomething();
		}
	}
}