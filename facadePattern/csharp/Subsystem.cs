class Subsystem1
{
	public void Setup()
	{
		System.Console.WriteLine("Subsystem1: Ready");
	}

	public void Operation()
	{
		System.Console.WriteLine("Subsystem1: Operation in progress");
	}
}

class Subsystem2
{
	public void Setup()
	{
		System.Console.WriteLine("Subsystem2: Ready");
	}

	public void SayHi()
	{
		System.Console.WriteLine("Subsystem2: Saying Hi");
	}
}