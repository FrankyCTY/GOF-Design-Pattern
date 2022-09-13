// Component
abstract class VisualComponent
{
	public abstract void Draw();
}

// Concrete Component
class TextView : VisualComponent
{
	public override void Draw()
	{

		System.Console.WriteLine("Drawing for TextView");
	}

}