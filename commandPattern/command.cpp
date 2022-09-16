#include <iostream>
#include "./command.h"
#include "./receiver.h"

void HelloCommand::Execute()
{
	std::cout << "Hello Command" << std::endl;
}

WorldCommand::WorldCommand(Receiver *receiver)
{
	_receiver = receiver;
}

void WorldCommand::Execute()
{
	std::cout << "World Command" << std::endl;
	_receiver->ReceiverOperation();
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
