using Newtonsoft.Json;

public class CarData
{
	public string? Owner { get; set; }

	public string? Number { get; set; }

	public string? Company { get; set; }

	public string? Model { get; set; }

	public string? Color { get; set; }
}

// The Flyweight stores a common portion of the state (also called intrinsic/share
// state) that belongs to multiple real business entities. The Flyweight
// accepts the rest of the state (extrinsic/unique state, unique for each entity) via its method parameters.
public class Flyweight
{
	private CarData _sharedState;

	public Flyweight(CarData car)
	{
		this._sharedState = car;
	}

	public void PrintInfo(CarData uniqueState)
	{
		string serializedSharedState = JsonConvert.SerializeObject(this._sharedState);
		string serializedUniqueState = JsonConvert.SerializeObject(uniqueState);
		Console.WriteLine($"Flyweight: Displaying shared {serializedSharedState} and unique {serializedUniqueState} state.");
	}
}