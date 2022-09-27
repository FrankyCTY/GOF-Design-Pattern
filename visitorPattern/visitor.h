#pragma once
#include "./element.h"

class Visitor
{
public:
	virtual void VisitConcreteComponentA(ConcreteComponentA *concreteComponentA) = 0;
	virtual void VisitConcreteComponentB(ConcreteComponentB *concreteComponentB) = 0;
};

class ConcreteVisitor : public Visitor
{
public:
	void VisitConcreteComponentA(ConcreteComponentA *concreteComponentA);

	void VisitConcreteComponentB(ConcreteComponentB *concreteComponentB);
};
