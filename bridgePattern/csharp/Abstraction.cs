static class ImplementationFactory
{
	public static WindowImp CreateImplementation()
	{
		return new PMWindowImp();
	}
}

// ============= Abstraction =============
abstract class Window
{
	protected WindowImp _imp;

	public Window()
	{
		// Use factory method
		_imp = ImplementationFactory.CreateImplementation();
	}

	// requests handled by abstraction
	public abstract void DrawContents();
	// requests forwarded to implementation
	public void DrawRect()
	{
		_imp.DeviceRect();
	}


}

// ============= Refined Abstraction =============
class ApplicationWindow : Window
{
	public override void DrawContents()
	{
		System.Console.WriteLine("Draw contents for ApplicationWindow");
	}
}

class IconWindow : Window
{
	public override void DrawContents()
	{
		System.Console.WriteLine("Draw contents for IconWindow");
	}
}