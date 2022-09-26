#pragma once
#include "./context.h"
#include <iostream>

class State
{
public:
	virtual void Handler1() = 0;
	virtual void Handler2() = 0;

protected:
	void SetContext(Context *context);

protected:
	Context *_context;
};

class ConcreteStateA : public State
{
public:
	void Handler1();

	void Handler2();
};

class ConcreteStateB : public State
{
public:
	void Handler1();

	void Handler2();
};
