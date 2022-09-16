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

class HelloCommand : public Command
{
public:
	explicit HelloCommand();
	void Execute();
};

class WorldCommand : public Command
{
public:
	explicit WorldCommand(Receiver *);
	void Execute();

private:
	Receiver *_receiver;
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
