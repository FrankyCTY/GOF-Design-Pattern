#include "./facade.h"
#include "./subsystemComponent.h"

int main()
{
	// Client code can use facade
	Subsystem1 *subsystem1 = new Subsystem1();
	Facade *facade = new Facade(subsystem1);
	facade->Operation();

	// Client code can also directly send request to subsystem object if it is needed
	Subsystem1 *subsystem1b = new Subsystem1();
	Subsystem2 *subsystem2b = new Subsystem2();
	subsystem1b->Operation();
	subsystem2b->SayHi();
}