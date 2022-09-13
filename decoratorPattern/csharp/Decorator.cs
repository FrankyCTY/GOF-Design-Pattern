// Decorator
abstract class Decorator : VisualComponent
{
	protected VisualComponent _component;

	public Decorator(VisualComponent component)
	{
		_component = component;
	}

	public override void Draw()
	{
		// Default to direct forwarding
		_component.Draw();
	}
}

// Concrete Decorator
class BorderDecorator : Decorator
{
	private int _width;

	public BorderDecorator(VisualComponent component, int borderWidth) : base(component)
	{
		_width = borderWidth;
	}

	public override void Draw()
	{
		_component.Draw();
		DrawBorder(_width);
		System.Console.WriteLine("Border decorator");
	}

	private void DrawBorder(int width)
	{
		System.Console.WriteLine($"Drawing border with width {width}");
	}
}

// Concrete Decorator
class ScrollbarDecorator : Decorator
{
	public ScrollbarDecorator(VisualComponent component) : base(component)
	{
	}

	public override void Draw()
	{
		_component.Draw();
		System.Console.WriteLine("Scrollbar decorator");
	}
}