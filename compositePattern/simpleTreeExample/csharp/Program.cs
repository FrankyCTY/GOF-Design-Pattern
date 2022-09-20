static class Client
{
	// The client code works with all of the components via the base
	// interface.
	public static void ExecuteComponent(Component component)
	{
		Console.WriteLine($"RESULT: {component.Operation()}\n");
	}

	// Thanks to the fact that the child-management operations are declared
	// in the base Component class, the client code can work with any
	// component, simple or complex, without depending on their concrete
	// classes.
	public static void AddToComposite(Component component1, Component component2)
	{
		if (component1.IsComposite())
		{
			component1.Add(component2);
		}

		Console.WriteLine($"RESULT: {component1.Operation()}");
	}
}

namespace CompositePattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Leaf leaf = new Leaf();
			Console.WriteLine("# Executing leaf component");
			Client.ExecuteComponent(leaf);

			Composite tree = new Composite();
			Composite branch1 = new Composite();
			branch1.Add(new Leaf());
			branch1.Add(new Leaf());
			Composite branch2 = new Composite();
			branch2.Add(new Leaf());
			tree.Add(branch1);
			tree.Add(branch2);
			Console.WriteLine("# Executing composite component");
			Client.ExecuteComponent(tree);

			Console.Write("# Adding 1 more leaf into composite component\n");
			Client.AddToComposite(tree, leaf);
		}
	}
}


// // ============== Output ==============
// # Executing leaf component
// RESULT: Leaf

// # Executing composite component
// RESULT: Branch(Branch(Leaf+Leaf)+Branch(Leaf))

// # Adding 1 more leaf into composite component
// RESULT: Branch(Branch(Leaf+Leaf)+Branch(Leaf)+Leaf)