namespace MementoPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			string originalState = "original state";
			Originator originator = new Originator(originalState);

			CareTaker careTaker = new CareTaker(originator);
			careTaker.Backup();
			careTaker.PrintSnapshotsInfo();

			System.Console.WriteLine("\nClient: Ready to perform operation on originator and save again\n");

			originator.BusinessOperation();
			careTaker.Backup();
			careTaker.PrintSnapshotsInfo();

			System.Console.WriteLine("\nClient: Ready to store last snapshot of originator\n");

			careTaker.Restore();
			careTaker.PrintSnapshotsInfo();
		}
	}
}