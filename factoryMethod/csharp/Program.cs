namespace FactoryMethodPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Creator concreteCreator1 = new ConcreteCreator1();
			concreteCreator1.BusinessOperation();

			System.Console.WriteLine("");

			Creator concreteCreator2 = new ConcreteCreator2();
			concreteCreator2.BusinessOperation();
		}
	}
}