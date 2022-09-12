// Proxy
class ImageProxy : Graphic
{
	private Image? _image;
	// Keep soft reference (not actual object) to file
	private string _fileName;
	private Point _extent;

	public ImageProxy(string fileName)
	{
		_fileName = fileName;
		_extent = new Point(0);
		// _image remain empty
	}

	// Control access to create object - Use cached image if exist
	private Image GetImage()
	{
		if (_image is null)
		{
			_image = new Image(_fileName);
		}

		return _image;
	}

	public override void Draw(Point at)
	{
		GetImage().Draw(at);
	}

	public override void Load(string from)
	{
		GetImage().Load(from);
	}

	public override void Save(string to)
	{
		GetImage().Save(to);
	}

	public override Point GetExtent()
	{
		if (_extent != null && _extent.getP() != 0)
		{
			_extent = GetImage().GetExtent();
		}

		return _extent!;
	}
}