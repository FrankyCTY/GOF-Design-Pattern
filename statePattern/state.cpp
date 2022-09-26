#include "./state.h"

void State::SetContext(Context *context)
{
	_context = context;
}

// ================ Concrete State A ================
void ConcreteStateA::Handler1()
{
	printf("ConcreteStateA handles request1.\n");
	printf("ConcreteStateA wants to change the state of the context.\n");
	this->_context->TransitionState(new ConcreteStateB());
}

void ConcreteStateA::Handler2()
{
	printf("ConcreteStateA handles request2.\n");
}

// ================ Concrete State B ================
void ConcreteStateB::Handler1()
{
	printf("ConcreteStateB handles request1.\n");
}

void ConcreteStateB::Handler2()
{
	printf("ConcreteStateB handles request2.\n");
	printf("ConcreteStateB wants to change the state of the context.\n");
	this->_context->TransitionState(new ConcreteStateB());
}