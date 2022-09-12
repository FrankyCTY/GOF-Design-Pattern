public abstract class Compositor
{
	public abstract int compose(int lineWidth);
}

public class SimpleCompositor : Compositor
{
	public override int compose(int lineWidth)
	{
		System.Console.WriteLine("composing");
		return 0;
	}
}

public class TeXCompositor : Compositor
{
	public override int compose(int lineWidth)
	{
		System.Console.WriteLine("composing");
		return 0;
	}
}

public class ArrayCompositor : Compositor
{
	public override int compose(int lineWidth)
	{
		System.Console.WriteLine("composing");
		return 0;
	}
}