
// Subject
public abstract class Graphic
{
	public abstract void Draw(Point at);
	public abstract void Load(string from);
	public abstract void Save(string to);

	public abstract Point GetExtent();
}

// Real Subject
public class Image : Graphic
{
	public Image(string fileName)
	{
		System.Console.WriteLine($"Loading file {fileName}");
	}

	public override void Draw(Point at)
	{
		System.Console.WriteLine("Drawing");
	}

	public override Point GetExtent()
	{
		System.Console.WriteLine("Getting Extent");
		return new Point(999);
	}

	public override void Load(string from)
	{
		System.Console.WriteLine("Loading file");
	}

	public override void Save(string to)
	{
		System.Console.WriteLine("Saving file");
	}
}