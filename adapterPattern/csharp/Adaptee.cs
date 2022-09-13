// =============== Adaptee ===============
abstract class TextView
{
	public void GetOrigin(Coord x, Coord y)
	{
		System.Console.WriteLine("Text View Get Origin");
	}
	public abstract bool IsEmpty();
}
