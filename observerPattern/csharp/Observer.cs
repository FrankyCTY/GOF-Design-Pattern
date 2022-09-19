interface IObserver
{
	public void Update(ISubject subject);
}

class ObserverA : IObserver
{
	public void Update(ISubject subject)
	{
		// Ensure the subject has state instance variable
		if ((subject as Subject)?.State < 3)
		{
			System.Console.WriteLine("ObserverA: Reacted to the event.");
		}
	}
}

class ObserverB : IObserver
{
	public void Update(ISubject subject)
	{
		// Ensure the subject has state instance variable
		if ((subject as Subject)?.State == 0 || (subject as Subject)?.State >= 2)
		{
			System.Console.WriteLine("ObserverB: Reacted to the event.");
		}
	}
}
