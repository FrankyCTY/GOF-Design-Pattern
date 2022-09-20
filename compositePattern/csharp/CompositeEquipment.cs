abstract class CompositeEquipment : Equipment
{
	protected List<Equipment> _equipments = new();

	protected CompositeEquipment()
	{
		_name = "CompositeEquipment";
	}

	public override void Add(Equipment equipment)
	{
		_equipments.Add(equipment);
	}

	public override void Remove(Equipment equipment)
	{
		_equipments.Remove(equipment);
	}

	public override int NetPrice()
	{
		var totalNetPrice = 0;

		// Can use iterator pattern here
		foreach (var equipment in _equipments)
		{
			totalNetPrice += equipment.NetPrice();
		}

		return totalNetPrice;
	}

	public override int Power()
	{
		var totalPowerInWatts = 0;

		// Can use iterator pattern here
		foreach (var equipment in _equipments)
		{
			totalPowerInWatts += equipment.Power();
		}

		return totalPowerInWatts;
	}
}

// 機殼
class Chassis : CompositeEquipment
{
	public Chassis()
	{
		_name = "Chassis";
	}

	public override void Add(Equipment equipment)
	{
		List<String> acceptableEquipments = new List<string> { "Motherboard", "Cpu" };
		if (acceptableEquipments.Contains(equipment.GetName()))
		{
			_equipments.Add(equipment);
			return;
		}

		System.Console.WriteLine("Our Chassis can not contain useless equipment!!");
	}
}