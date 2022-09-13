namespace DecoratorPattern
{
	class Window
	{
		public void SetContents(VisualComponent contents)
		{
			contents.Draw();
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			Window window = new();
			window.SetContents(new BorderDecorator(new ScrollbarDecorator(new TextView()), 10));
		}
	}
}