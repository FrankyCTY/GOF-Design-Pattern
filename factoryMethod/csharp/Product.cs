public interface IProduct
{
	void DoSomething();
}

class ConcreteProduct1 : IProduct
{
	public void DoSomething()
	{
		System.Console.WriteLine("Concrete Product 1: Doing Something");
	}
}

class ConcreteProduct2 : IProduct
{
	public void DoSomething()
	{
		System.Console.WriteLine("Concrete Product 2: Doing Something");
	}
}