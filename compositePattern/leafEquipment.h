#pragma once
#include "./equipment.h"

class Motherboard : public Equipment
{
public:
	Motherboard();
	int NetPrice() override;
	int Power() override;
};

class Cpu : public Equipment
{
public:
	Cpu();
	int NetPrice() override;
	int Power() override;
};

class UselessEquipment : public Equipment
{
public:
	UselessEquipment();
	int NetPrice() override;
	int Power() override;
};
