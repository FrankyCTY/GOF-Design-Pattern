#pragma once
#include <list>
#include "./equipment.h"
#include "./leafEquipment.h"

class CompositeEquipment : public Equipment
{
public:
	CompositeEquipment();
	virtual void Add(Equipment *equipment);
	void Remove(Equipment *equipment);

	virtual int NetPrice();
	virtual int Power();

protected:
	std::list<Equipment *> _equipments;
};

// 機殼
class Chassis : public CompositeEquipment
{
public:
	Chassis();
	void Add(Equipment *equipment) override;
};