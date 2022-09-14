#include <iostream>
#include "./command.h"
#include "./receiver.h"

OpenCommand::OpenCommand(Application *application)
{
	_application = application;
}

char *OpenCommand::PromptUserForDocName() const
{
	std::cout << "Which document do you want to open?" << std::endl;
	return "fake doc name";
}

void OpenCommand::Execute()
{
	char *docName = PromptUserForDocName();

	if (docName != 0)
	{
		Document *document = new Document(docName);
		_application->Add(document);
	}
}

HelloCommand::HelloCommand()
{
}

void HelloCommand::Execute()
{
	std::cout << "Hello Command" << std::endl;
}

void MarcoCommand::AddCommand(Command *command)
{
	_commands->push_front(command);
}

void MarcoCommand::RemoveCommand(Command *command)
{
	_commands->remove(command);
}

void MarcoCommand::Execute()
{
	list<Command *>::iterator it;

	for (it = _commands->begin(); it != _commands->end(); ++it)
	{
		Command *currentCommand = *it;
		currentCommand->Execute();
	}
}
