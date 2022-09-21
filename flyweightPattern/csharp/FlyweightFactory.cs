// The Flyweight Factory creates and manages the Flyweight objects. It
// ensures that flyweights are shared correctly. When the client requests a
// flyweight, the factory either returns an existing instance or creates a
// new one, if it doesn't exist yet.
public class FlyweightFactory
{
	private List<Tuple<Flyweight, string>> flyweights = new List<Tuple<Flyweight, string>>();

	public FlyweightFactory(params CarData[] cars)
	{
		foreach (var car in cars)
		{
			flyweights.Add(new Tuple<Flyweight, string>(new Flyweight(car), this.generateCacheKey(car)));
		}
	}

	// Generate car identifier based on car data
	public string generateCacheKey(CarData car)
	{
		List<string?> elements = new List<string?>();

		elements.Add(car.Model);
		elements.Add(car.Color);
		elements.Add(car.Company);

		if (car.Owner != null && car.Number != null)
		{
			elements.Add(car.Number);
			elements.Add(car.Owner);
		}

		elements.Sort();

		return string.Join("_", elements);
	}

	// Returns an existing Flyweight with a given state or creates a new one.
	public Flyweight GetFlyweight(CarData sharedState)
	{
		string cacheKey = this.generateCacheKey(sharedState);

		bool foundCachedCar = flyweights.Where(carToKey => carToKey.Item2 == cacheKey).Count() > 0;
		if (foundCachedCar)
		{
			Console.WriteLine("FlyweightFactory: Reusing existing flyweight.");
			return this.flyweights.Where(t => t.Item2 == cacheKey)!.FirstOrDefault()!.Item1;
		}

		Console.WriteLine("FlyweightFactory: Can't find a flyweight, creating new one.");
		this.flyweights.Add(new Tuple<Flyweight, string>(new Flyweight(sharedState), cacheKey));
		return this.flyweights.Where(t => t.Item2 == cacheKey)!.FirstOrDefault()!.Item1;
	}

	public void listFlyweights()
	{
		Console.WriteLine($"\nFlyweightFactory: I have {flyweights.Count} flyweights:");
		foreach (var flyweight in flyweights)
		{
			Console.WriteLine(flyweight.Item2);
		}
	}
}
