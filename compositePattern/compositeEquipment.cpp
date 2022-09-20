#include <iostream>
#include "./compositeEquipment.h"

CompositeEquipment::CompositeEquipment()
{
	_name = "CompositeEquipment";
}

void CompositeEquipment::Add(Equipment *equipment)
{
	_equipments.push_back(equipment);
}

void CompositeEquipment::Remove(Equipment *equipment)
{
	_equipments.remove(equipment);
}

int CompositeEquipment::NetPrice()
{
	int totalNetPrice = 0;

	std::list<Equipment *>::iterator iterator = _equipments.begin();
	while (iterator != _equipments.end())
	{
		totalNetPrice += (*iterator)->NetPrice();
		++iterator;
	}

	delete *iterator;
	return totalNetPrice;
}

int CompositeEquipment::Power()
{
	int totalPowerInWatts = 0;

	std::list<Equipment *>::iterator iterator = _equipments.begin();
	while (iterator != _equipments.end())
	{
		totalPowerInWatts += (*iterator)->Power();
		++iterator;
	}

	delete *iterator;
	return totalPowerInWatts;
}

Chassis::Chassis()
{
	_name = "Chassis";
}

void Chassis::Add(Equipment *equipment)
{
	bool isAcceptable = false;
	std::string acceptableEquipments[2] = {"Motherboard", "Cpu"};
	for (std::string ae : acceptableEquipments)
	{
		if (equipment->GetName() == ae)
		{
			_equipments.push_back(equipment);
			isAcceptable = true;
		}
	}

	if (!isAcceptable)
	{
		std::cout << "Our Chassis can not contain useless equipment!!" << std::endl;
	}
}