#include "./element.h"
#include "./visitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	vector<Component *> components;
	ConcreteComponentA *concreteComponentA = new ConcreteComponentA();
	ConcreteComponentB *concreteComponentB = new ConcreteComponentB();

	components.push_back(concreteComponentA);
	components.push_back(concreteComponentB);

	vector<Component *>::iterator it;

	Visitor *concreteVisitor = new ConcreteVisitor();

	for (it = components.begin(); it < components.end(); it++)
	{
		(*it)->Accept(concreteVisitor);
	}

	delete concreteVisitor;

	return 0;
};

// Visit Concrete Component A
// Method Exclusive To Component A
// Visit Concrete Component B
// Method Special To Component B