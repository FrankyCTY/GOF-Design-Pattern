namespace VisitorPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			List<IComponent> components = new List<IComponent>
						{
								new ConcreteComponentA(),
								new ConcreteComponentB()
						};

			Console.WriteLine("The client code works with all visitors via the base Visitor interface:");
			var visitor1 = new ConcreteVisitor1();
			foreach (var component in components)
			{
				component.Accept(visitor);
			}

			Console.WriteLine();

			Console.WriteLine("It allows the same client code to work with different types of visitors:");
			var visitor2 = new ConcreteVisitor2();
			foreach (var component in components)
			{
				component.Accept(visitor);
			}
		}
	}
}

// The client code works with all visitors via the base Visitor interface:
// A + ConcreteVisitor1
// B + ConcreteVisitor1

// It allows the same client code to work with different types of visitors:
// A + ConcreteVisitor2
// B + ConcreteVisitor2