#include <iostream>
#include "./compositeEquipment.h"
#include "./leafEquipment.h"

int main()
{
	Chassis *chassis = new Chassis();
	chassis->Add(new Motherboard());
	chassis->Add(new Cpu());
	std::cout << "Installed chassis" << std::endl;
	std::cout << "Total price = " << chassis->NetPrice() << ", Total power = " << chassis->Power() << "\n\n";

	std::cout << "Ready to add incompatible equipment to chassis" << std::endl;
	chassis->Add(new UselessEquipment());

	return 0;
}