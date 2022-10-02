namespace PrototypePattern
{

	class Program
	{
		static void Main(string[] args)
		{
			Person original = new Person(42, Convert.ToDateTime("1977-01-01"), "Franky Dude", new IdInfo(666));

			Person shallowCopy = original.ShallowCopy();
			Person deepCopy = original.DeepCopy();

			Console.WriteLine("========== Display all object's info: ==========");
			Console.WriteLine("1. Original instance values: ");
			DisplayValues(original);
			Console.WriteLine("2. ShallowCopy instance values:");
			DisplayValues(shallowCopy);
			Console.WriteLine("3. DeepCopy instance values:");
			DisplayValues(deepCopy);

			System.Console.WriteLine("");

			original.Age = 32;
			original.BirthDate = Convert.ToDateTime("1900-01-01");
			original.Name = "A Changed Name";
			original.IdInfo.IdNumber = 7878;
			Console.WriteLine("\n========== Display all object's info after making changes to Original object: ==========");
			Console.WriteLine("1. Original instance values: ");
			DisplayValues(original);
			Console.WriteLine("2. ShallowCopy instance values (reference values have changed):");
			DisplayValues(shallowCopy);
			Console.WriteLine("3. DeepCopy instance values (everything was kept the same):");
			DisplayValues(deepCopy);
		}

		public static void DisplayValues(Person p)
		{
			Console.WriteLine("Name: {0:s}, Age: {1:d}, BirthDate: {2:MM/dd/yy}",
					p.Name, p.Age, p.BirthDate);
			Console.WriteLine("Reference Value -> ID#: {0:d}", p.IdInfo.IdNumber);
		}
	}
}

// ========== Display all object's info: ==========
// 1. Original instance values:
// Name: Franky Dude, Age: 42, BirthDate: 01/01/77
// Reference Value -> ID#: 666
// 2. ShallowCopy instance values:
// Name: Franky Dude, Age: 42, BirthDate: 01/01/77
// Reference Value -> ID#: 666
// 3. DeepCopy instance values:
// Name: Franky Dude, Age: 42, BirthDate: 01/01/77
// Reference Value -> ID#: 666


// ========== Display all object's info after making changes to Original object: ==========
// 1. Original instance values:
// Name: A Changed Name, Age: 32, BirthDate: 01/01/00
// Reference Value -> ID#: 7878
// 2. ShallowCopy instance values (reference values have changed):
// Name: Franky Dude, Age: 42, BirthDate: 01/01/77
// Reference Value -> ID#: 7878
// 3. DeepCopy instance values (everything was kept the same):
// Name: Franky Dude, Age: 42, BirthDate: 01/01/77
// Reference Value -> ID#: 666