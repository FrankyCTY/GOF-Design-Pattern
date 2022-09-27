#include "./element.h"
#include "./visitor.h"

void ConcreteComponentA::Accept(Visitor *visitor)
{
	visitor->VisitConcreteComponentA(this);
}

void ConcreteComponentA::MethodExclusiveToComponentA()
{
	cout << "Method Exclusive To Component A" << endl;
}

void ConcreteComponentB::Accept(Visitor *visitor)
{
	visitor->VisitConcreteComponentB(this);
}

void ConcreteComponentB::MethodSpecialToComponentB()
{
	cout << "Method Special To Component B" << endl;
}
