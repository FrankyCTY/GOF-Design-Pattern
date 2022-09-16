abstract class Widget
{
	protected DialogMediator? _mediator;

	public void Change()
	{
		if (_mediator is DialogMediator)
		{
			_mediator.Notify(this);
		}
	}

	public void SetMediator(DialogMediator mediator)
	{
		_mediator = mediator;
	}
}

class ListBox : Widget
{
	public string GetSelectedItemValue()
	{
		System.Console.WriteLine("Getting selected item value from list box");
		return "selected item value";
	}
}

class TextField : Widget
{
	private string? _text;

	public void SetText(string text)
	{
		System.Console.WriteLine("Setting the text for the text field");
		_text = text;
	}
}

class Button : Widget
{
	public void DoSomething()
	{
		System.Console.WriteLine("Button clicked");
	}
}