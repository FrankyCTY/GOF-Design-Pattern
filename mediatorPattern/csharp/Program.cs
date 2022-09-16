namespace MediatorPattern
{
	class Program
	{
		static void Main(string[] args)
		{
			ListBox listBox = new ListBox();
			TextField textField = new TextField();
			Button submitBtn = new Button();

			FontDialogMediator fontDialogMediator = new FontDialogMediator(listBox, textField, submitBtn);

			listBox.Change();
			submitBtn.Change();
		}
	}
}