namespace SingletonPattern
{
	// EN : The Singleton should always be a 'sealed' class to prevent class
	// inheritance through external classes and also through nested classes.
	public sealed class Singleton
	{
		private Singleton() { }

		private static Singleton _instance;

		public static Singleton GetInstance()
		{
			if (_instance == null)
			{
				_instance = new Singleton();
			}
			return _instance;
		}

		public void BusinessOperation()
		{
			System.Console.WriteLine("Other business operation");
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			// We didn't use static class here
			Singleton s1 = Singleton.GetInstance();
			Singleton s2 = Singleton.GetInstance();

			if (s1 == s2)
			{
				Console.WriteLine("Singleton works, both variables contain the same instance.");
			}
			else
			{
				Console.WriteLine("Singleton failed, variables contain different instances.");
			}
		}
	}
}

// Singleton works, both variables contain the same instance.