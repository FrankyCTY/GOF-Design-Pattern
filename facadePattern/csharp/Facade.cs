class Facade
{
	// Can let client decide which subsystem1 to use
	private Subsystem1 _subsystem1;
	// Can have fixed dependency on certain object
	private Subsystem2 _subsystem2 = new Subsystem2();

	public Facade(Subsystem1 subsystem1)
	{
		_subsystem1 = subsystem1;
	}

	public void Operation()
	{
		System.Console.WriteLine("Facade operation started!");
		_subsystem1.Setup();
		_subsystem1.Operation();
		System.Console.WriteLine("Subsystem1 DONE");
		_subsystem2.Setup();
		_subsystem2.SayHi();
	}
}