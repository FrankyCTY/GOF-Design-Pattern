public interface IButton
{
	void OnClick(ITextField textField);
}

class DarkModeButton : IButton
{
	public void OnClick(ITextField textField)
	{
		System.Console.WriteLine("Dark Mode Button: Clicked");
		System.Console.WriteLine($"Dark Mode Button: Submitting Text Field Value -> {textField.GetText()}");
	}
}

class WhiteModeButton : IButton
{
	public void OnClick(ITextField textField)
	{
		System.Console.WriteLine("White Mode Button: Clicked");
		System.Console.WriteLine($"White Mode Button: Submitting Text Field Value -> {textField.GetText()}");
	}
}

public interface ITextField
{
	string GetText();
}

class DarkModeTextField : ITextField
{
	public string GetText()
	{
		return "Dark Mode Text Field's Value";
	}
}

class WhiteModeTextField : ITextField
{
	public string GetText()
	{
		return "White Mode Text Field's Value";
	}
}