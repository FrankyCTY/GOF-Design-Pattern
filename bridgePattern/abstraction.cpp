// ============= Refined Abstraction =============#include "common.h"
#include "implementation.h"
#include "./abstraction.h"
#include <iostream>

class ImplementationFactory
{
public:
	static WindowImp *CreateImplementation()
	{
		return new PMWindowImp();
	}

private:
	ImplementationFactory(){};
};

// ============= Abstraction =============
Window::Window()
{
	_imp = ImplementationFactory::CreateImplementation();
}

void Window::DrawRect()
{
	_imp->DeviceRect();
}

// ============= Refined Abstraction =============
void ApplicationWindow::DrawContents()
{
	std::cout << "Draw contents for ApplicationWindow" << std::endl;
}

// ============= Refined Abstraction =============
void IconWindow::DrawContents()
{
	std::cout << "Draw contents for IconWindow" << std::endl;
}
