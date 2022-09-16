abstract class Command
{
	public abstract void Execute();
}

class HelloCommand : Command
{
	public override void Execute()
	{
		System.Console.WriteLine("Hello Command");
	}
}

class WorldCommand : Command
{
	private Receiver _receiver;

	public WorldCommand(Receiver receiver)
	{
		_receiver = receiver;
	}

	public override void Execute()
	{
		System.Console.WriteLine("World Command");
		_receiver.ReceiverOperation();
	}
}

class MarcoCommand : Command
{
	private List<Command> commands = new List<Command>();

	public void AddCommand(Command command)
	{
		commands.Add(command);
	}


	public void RemoveCommand(Command command)
	{
		commands.Remove(command);
	}

	public override void Execute()
	{
		commands.ForEach(delegate (Command command)
		{
			command.Execute();
		});
	}
}