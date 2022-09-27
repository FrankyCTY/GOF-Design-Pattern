#include "./visitor.h"
#include <iostream>

using namespace std;

void ConcreteVisitor::VisitConcreteComponentA(ConcreteComponentA *concreteComponentA)
{
	cout << "Visit Concrete Component A" << endl;
	concreteComponentA->MethodExclusiveToComponentA();
}

void ConcreteVisitor::VisitConcreteComponentB(ConcreteComponentB *concreteComponentB)
{
	cout << "Visit Concrete Component B" << endl;
	concreteComponentB->MethodSpecialToComponentB();
}
