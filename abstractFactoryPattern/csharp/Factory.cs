public interface IAbstractFactory
{
	IButton CreateButton();

	ITextField CreateTextField();
}

class DarkModeFactory : IAbstractFactory
{
	public IButton CreateButton()
	{
		return new DarkModeButton();
	}

	public ITextField CreateTextField()
	{
		return new DarkModeTextField();
	}
}

class WhiteModeFactory : IAbstractFactory
{
	public IButton CreateButton()
	{
		return new WhiteModeButton();
	}

	public ITextField CreateTextField()
	{
		return new WhiteModeTextField();
	}
}