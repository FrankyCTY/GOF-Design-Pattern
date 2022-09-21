class Program
{
	public static void AddCachedCarToDb(FlyweightFactory factory, CarData car)
	{
		Console.WriteLine("\nClient: Adding cached car to DB.");

		var carFlyweight = factory.GetFlyweight(new CarData
		{
			Color = car.Color,
			Model = car.Model,
			Company = car.Company
		});


		carFlyweight.PrintInfo(car);
	}

	public static void AddNewCarToDb(FlyweightFactory factory, CarData car)
	{
		Console.WriteLine("\nClient: Adding new car to DB.");

		var carFlyweight = factory.GetFlyweight(new CarData
		{
			Color = car.Color,
			Model = car.Model,
			Company = car.Company
		});


		carFlyweight.PrintInfo(car);
	}

	static void Main(string[] args)
	{
		var factory = new FlyweightFactory(
				new CarData { Company = "Chevrolet", Model = "Camaro2018", Color = "pink" },
				new CarData { Company = "Mercedes Benz", Model = "C300", Color = "black" },
				new CarData { Company = "Mercedes Benz", Model = "C500", Color = "red" },
				new CarData { Company = "BMW", Model = "M5", Color = "red" },
				new CarData { Company = "BMW", Model = "X6", Color = "white" }
		);
		factory.listFlyweights();

		AddCachedCarToDb(factory, new CarData
		{
			Number = "CL234IR",
			Owner = "James Doe",
			Company = "BMW",
			Model = "M5",
			Color = "red"
		});

		AddNewCarToDb(factory, new CarData
		{
			Number = "CL234IR",
			Owner = "James Doe",
			Company = "BMW",
			Model = "X1",
			Color = "red"
		});

		factory.listFlyweights();
	}


}

// =============== Output ===============
// FlyweightFactory: I have 5 flyweights:
// Camaro2018_Chevrolet_pink
// black_C300_Mercedes Benz
// C500_Mercedes Benz_red
// BMW_M5_red
// BMW_white_X6

// Client: Adding cached car to DB.
// FlyweightFactory: Reusing existing flyweight.
// Flyweight: Displaying shared {"Owner":null,"Number":null,"Company":"BMW","Model":"M5","Color":"red"} and unique {"Owner":"James Doe","Number":"CL234IR","Company":"BMW","Model":"M5","Color":"red"} state.

// Client: Adding new car to DB.
// FlyweightFactory: Can't find a flyweight, creating new one.
// Flyweight: Displaying shared {"Owner":null,"Number":null,"Company":"BMW","Model":"X1","Color":"red"} and unique {"Owner":"James Doe","Number":"CL234IR","Company":"BMW","Model":"X1","Color":"red"} state.

// FlyweightFactory: I have 6 flyweights:
// Camaro2018_Chevrolet_pink
// black_C300_Mercedes Benz
// C500_Mercedes Benz_red
// BMW_M5_red
// BMW_white_X6
// BMW_red_X1