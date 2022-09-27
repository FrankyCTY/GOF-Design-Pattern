class CareTaker
{
	private Originator _originator;
	private List<Memento> _snapshots;

	public CareTaker(Originator originator)
	{
		_originator = originator;
		_snapshots = new List<Memento>();
	}

	public void Backup()
	{
		System.Console.WriteLine("CareTaker: Received request to back up originator");
		Memento snapshot = _originator.CreateSnapshot();
		_snapshots.Add(snapshot);
	}

	public void Restore()
	{
		System.Console.WriteLine("CareTaker: Received request to restore old snapshot for originator");
		if (_snapshots.Count == 0)
		{
			System.Console.WriteLine("CareTaker: No snapshot found for originator to load\n");
		}

		Memento lastSnapshot = _snapshots.Last();
		_originator.LoadSnapshot(lastSnapshot);

		_snapshots.Remove(lastSnapshot);
	}

	public void PrintSnapshotsInfo()
	{
		System.Console.WriteLine("CareTaker: Received request to print snapshots info");

		int counter = 1;
		foreach (var snapshot in _snapshots)
		{
			System.Console.WriteLine($"{counter}. {snapshot.GetState()}");
			counter++;
		}
	}
}
