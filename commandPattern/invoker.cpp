#include <iostream>
#include "./invoker.h"
#include "./command.h"

void SubmitButton::SetCommand(Command *command)
{
	_command = command;
}

void SubmitButton::Submit()
{
	std::cout << "Ready to submit" << std::endl;
	if (_command != 0)
	{
		_command->Execute();
	}
}