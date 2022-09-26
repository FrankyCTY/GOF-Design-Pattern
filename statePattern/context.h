#pragma once
#include "./state.h"

class Context
{
public:
	Context(State *state);

	void TransitionState(State *state);

	void Request1();

	void Request2();

private:
	State *_state;
};
