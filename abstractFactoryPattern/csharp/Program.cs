namespace AbstractFactorPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Client: Dark Mode");
			ClientMethod(new DarkModeFactory());
			Console.WriteLine();

			Console.WriteLine("Client: White Mode");
			ClientMethod(new WhiteModeFactory());
		}

		static public void ClientMethod(IAbstractFactory factory)
		{
			var button = factory.CreateButton();
			var textField = factory.CreateTextField();

			button.OnClick(textField);
		}
	}
}

// Client: Dark Mode
// Dark Mode Button: Clicked
// Dark Mode Button: Submitting Text Field Value -> Dark Mode Text Field's Value

// Client: White Mode
// White Mode Button: Clicked
// White Mode Button: Submitting Text Field Value -> White Mode Text Field's Value