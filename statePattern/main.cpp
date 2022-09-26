#include "./context.h"
#include "./state.h"

int main()
{
	State *state = new ConcreteStateA();
	Context *context = new Context(state);

	delete state;
	delete context;
	return 0;
}