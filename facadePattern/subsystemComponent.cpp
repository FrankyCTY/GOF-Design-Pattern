#include "./subsystemComponent.h"

void Subsystem1::Setup() const
{
	std::cout << "Subsystem1: Ready" << std::endl;
}

void Subsystem1::Operation() const
{
	std::cout << "Subsystem1: Operation in progress" << std::endl;
}

void Subsystem2::Setup() const
{
	std::cout << "Subsystem2: Ready" << std::endl;
}

void Subsystem2::SayHi() const
{
	std::cout << "Subsystem2: Saying Hi" << std::endl;
}