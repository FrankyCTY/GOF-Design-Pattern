// =============== Adapter ===============
class TextShape : Shape
{
	private TextView _textView;

	public TextShape(TextView textView)
	{
		_textView = textView;
	}

	// Convert TextView's interface to conform to Shape's interface
	public override void BoundingBox(Point bottomLeft, Point topRight)
	{
		Coord bottom = new();
		Coord left = new();
		_textView.GetOrigin(bottom, left);
		// ...
	}

	public override bool IsEmpty()
	{
		// Forward the request to the adpatee
		return _textView.IsEmpty();
	}

	public override void OtherMethod()
	{
		System.Console.WriteLine("Method that not supported by adaptee");
	}
}