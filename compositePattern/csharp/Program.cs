namespace CompositePatternEquipmentExample
{
	class Program
	{
		static void Main(string[] args)
		{
			Chassis chassis = new();
			chassis.Add(new Motherboard());
			chassis.Add(new Cpu());
			System.Console.WriteLine("Installed chassis");
			System.Console.WriteLine($"Total price = {chassis.NetPrice()}, Total power = {chassis.Power()}\n");

			System.Console.WriteLine("Ready to add incompatible equipment to chassis");
			chassis.Add(new UselessEquipment());
		}

	}
}


// ============== Output ==============
// Installed chassis
// Total price = 2000, Total power = 1000

// Ready to add incompatible equipment to chassis
// Our Chassis can not contain useless equipment!!