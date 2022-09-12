namespace ProxyPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			string imageFileName = "file name";
			// Virtual proxy control access to create expensive object (real subject)
			Graphic virtualProxy = new ImageProxy(imageFileName);
		}
	}
}