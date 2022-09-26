#include "./context.h"

Context::Context(State *state)
{
	TransitionState(state);
}

void Context::TransitionState(State *state)
{
	_state = state;
}

void Context::Request1()
{
	_state->Handler1();
}

void Context::Request2()
{
	_state->Handler2();
}