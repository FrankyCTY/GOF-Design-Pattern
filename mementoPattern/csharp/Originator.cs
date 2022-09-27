class Originator
{
	private string _state;

	public Originator(string state)
	{
		_state = state;
	}

	public Memento CreateSnapshot()
	{
		System.Console.WriteLine("Originator: Create snapshot");
		return new Memento(_state);
	}

	public void LoadSnapshot(Memento snapshot)
	{
		System.Console.WriteLine("Originator: Load snapshot");
		_state = snapshot.GetState();
	}

	public void BusinessOperation()
	{
		System.Console.WriteLine("Originator: Perform business operation");
		_state += ("+");
	}
}
