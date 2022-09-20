#include "./leafEquipment.h"

Motherboard::Motherboard()
{
	_name = "Motherboard";
}

int Motherboard::NetPrice()
{
	return 1000;
}

int Motherboard::Power()
{
	return 500;
}

Cpu::Cpu()
{
	_name = "Cpu";
}

int Cpu::NetPrice()
{
	return 1000;
}

int Cpu::Power()
{
	return 500;
}

UselessEquipment::UselessEquipment()
{
	_name = "UselessEquipment";
}

int UselessEquipment::NetPrice()
{
	return 1;
}

int UselessEquipment::Power()
{
	return 10;
}