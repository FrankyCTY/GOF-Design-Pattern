class SubmitButton
{
	private Command? _command;

	public void SetCommand(Command command)
	{
		_command = command;
	}

	public void Submit()
	{
		System.Console.WriteLine("Ready to submit");
		if (_command is Command)
		{
			_command.Execute();
		}
	}
}