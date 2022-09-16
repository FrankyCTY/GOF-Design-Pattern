namespace CommandPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			Command helloCommand = new HelloCommand();
			Receiver receiver = new Receiver();
			Command worldCommand = new WorldCommand(receiver);

			MarcoCommand marcoCommand = new MarcoCommand();
			marcoCommand.AddCommand(helloCommand);
			marcoCommand.AddCommand(worldCommand);

			SubmitButton submitBtn = new SubmitButton();
			submitBtn.SetCommand(marcoCommand);
			submitBtn.Submit();
		}
	}
}