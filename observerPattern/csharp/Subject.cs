interface ISubject
{
	public void Attach(IObserver observer);
	public void Detach(IObserver observer);
	public void Notify();
}

class Subject : ISubject
{
	public int State { get; set; } = 0;
	private List<IObserver> _observers = new List<IObserver>();

	public void Attach(IObserver observer)
	{
		_observers.Add(observer);
		System.Console.WriteLine("Subject: Attached an observer");
	}

	public void Detach(IObserver observer)
	{
		_observers.Remove(observer);
		System.Console.WriteLine("Subject: Detached an observer");
	}

	public void Notify()
	{
		System.Console.WriteLine("Subject: Notifying observers...");

		foreach (var observer in _observers)
		{
			observer.Update(this);
		}
	}

	// Subject is only 1 "role" the class has, it also have it's own business logic, state etc.
	public void SomeBusinessLogic()
	{
		Console.WriteLine("\nSubject: I'm doing something important.");
		this.State = new Random().Next(0, 10);

		Thread.Sleep(15);

		Console.WriteLine("Subject: My state has just changed to: " + this.State);
		this.Notify();
	}
}