abstract class Creator
{
	public abstract IProduct FactoryMethod();

	public void BusinessOperation()
	{
		var product = FactoryMethod();
		product.DoSomething();
		System.Console.WriteLine("Create: Finishing business operation");
	}
}

class ConcreteCreator1 : Creator
{
	public override IProduct FactoryMethod()
	{
		return new ConcreteProduct1();
	}
}

class ConcreteCreator2 : Creator
{
	public override IProduct FactoryMethod()
	{
		return new ConcreteProduct2();
	}
}