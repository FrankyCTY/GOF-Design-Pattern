#pragma once
#include "./command.h"

class SubmitButton
{
public:
	void SetCommand(Command *command);
	void Submit();

private:
	Command *_command;
};