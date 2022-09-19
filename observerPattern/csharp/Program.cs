namespace ObserverPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Subject subject = new();
			ObserverA observerA = new();
			subject.Attach(observerA);
			ObserverB observerB = new();
			subject.Attach(observerB);

			subject.SomeBusinessLogic();
			subject.SomeBusinessLogic();

			subject.Detach(observerB);
			subject.SomeBusinessLogic();
			subject.Detach(observerA);
			subject.SomeBusinessLogic();
		}
	}
}