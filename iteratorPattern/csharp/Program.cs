namespace IteratorPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			// The client code may or may not know about the Concrete Iterator
			// or Collection classes, depending on the level of indirection you
			// want to keep in your program.
			var collection = new WordsCollection();
			collection.AddItem("First");
			collection.AddItem("Second");
			collection.AddItem("Third");

			Console.WriteLine("Ascending traversal:");

			// In Csharp, we can override GetEnumerator() to define custom iterator
			foreach (var element in collection)
			{
				Console.WriteLine(element);
			}

			Console.WriteLine("\nDescending traversal:");
			collection.ReverseDirection();

			foreach (var element in collection)
			{
				Console.WriteLine(element);
			}
		}
	}
}
