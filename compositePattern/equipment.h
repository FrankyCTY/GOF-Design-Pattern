#pragma once
#include <string>

class Equipment
{
public:
	Equipment();

	virtual void Add(Equipment *equipment);
	virtual void Remove(Equipment *equipment);

	virtual std::string GetName();

	virtual int Power();
	virtual int NetPrice();

protected:
	std::string _name;
};