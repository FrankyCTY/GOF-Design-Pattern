#include "./invoker.h"
#include "./command.h"
// #include "./receiver.h"
using namespace std;

int main()
{
	// Command Invoker
	SubmitButton *submitBtn = new SubmitButton();

	// Concrete command 1's Receiver
	Application *application = new Application();
	// Concrete command 1
	Command *openCommand = new OpenCommand(application);

	// Concrete command 2
	Command *helloCommand = new HelloCommand();

	// Concrete marco command
	MarcoCommand *macroCommand = new MarcoCommand();

	macroCommand->AddCommand(openCommand);
	macroCommand->AddCommand(helloCommand);

	submitBtn->SetCommand(macroCommand);
}