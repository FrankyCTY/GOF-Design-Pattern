#pragma once
#include <iostream>
#include "./receiver.h"
#include <iterator>
#include <list>
using namespace std;

class Command
{
public:
	virtual ~Command();
	virtual void Execute() = 0;

protected:
	explicit Command();
};

class OpenCommand : public Command
{
public:
	explicit OpenCommand(Application *);
	void Execute();

private:
	char *PromptUserForDocName() const;

private:
	Application *_application;
};

class HelloCommand : public Command
{
public:
	explicit HelloCommand();
	void Execute();
};

class MarcoCommand : public Command
{
public:
	void AddCommand(Command *);
	void RemoveCommand(Command *);
	void Execute();

private:
	list<Command *> *_commands;
};
