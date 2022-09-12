public class Composition
{
	private Compositor _compositor;
	private int _lineWidth;

	public Composition(Compositor compositor)
	{
		_compositor = compositor;
	}

	public void Repair()
	{
		// ...
		_compositor.compose(_lineWidth);
		//...
	}
}