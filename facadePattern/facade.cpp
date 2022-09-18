#include "./facade.h"

Facade::Facade(Subsystem1 *subsystem1)
{
	_subsystem1 = subsystem1;
}

void Facade::Operation()
{
	std::cout << "Facade operation started!" << std::endl;
	_subsystem1->Setup();
	_subsystem1->Operation();
	std::cout << "Subsystem 1 DONE" << std::endl;
	_subsystem2->Setup();
	_subsystem2->SayHi();
}