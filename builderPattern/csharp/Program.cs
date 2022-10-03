namespace RefactoringGuru.DesignPatterns.Prototype.Conceptual
{
	class Program
	{
		static void Main(string[] args)
		{
			var builder = new ConcreteBuilder();
			var director = new Director(builder);
			director.Builder = builder;

			System.Console.WriteLine("=========== Using predefined configuration via Director ===========");
			Console.WriteLine("Standard basic product:");
			director.BuildMinimalViableProduct();
			Console.WriteLine(builder.GetProduct().ListParts());

			Console.WriteLine("Standard full featured product:");
			director.BuildFullFeaturedProduct();
			Console.WriteLine(builder.GetProduct().ListParts());


			System.Console.WriteLine("=========== Client directly uses builder ===========");
			Console.WriteLine("Custom product:");
			builder.BuildPartA();
			builder.BuildPartC();
			Console.Write(builder.GetProduct().ListParts());
		}
	}
}

// =========== Using predefined configuration via Director ===========
// Standard basic product:
// Product parts: PartA1

// Standard full featured product:
// Product parts: PartA1, PartB1, PartC1

// =========== Client directly uses builder ===========
// Custom product:
// Product parts: PartA1, PartC1