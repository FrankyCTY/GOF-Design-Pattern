#pragma once
#include <iostream>

using namespace std;

class Visitor;
class Component
{
public:
	virtual void Accept(Visitor *visitor) = 0;
};

class ConcreteComponentA : public Component
{
public:
	void Accept(Visitor *visitor);

	void MethodExclusiveToComponentA();
};

class ConcreteComponentB : public Component
{
public:
	void Accept(Visitor *visitor);

	void MethodSpecialToComponentB();
};
