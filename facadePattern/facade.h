#pragma once
#include "./subsystemComponent.h"

class Facade
{
private:
	// Can let client decide which subsystem1 to use
	Subsystem1 *_subsystem1;
	// Can have fixed dependency on certain object
	Subsystem2 *_subsystem2 = new Subsystem2();

public:
	Facade(Subsystem1 *Subsystem1);
	~Facade()
	{
		delete _subsystem1;
		delete _subsystem2;
	};
	void Operation();
};