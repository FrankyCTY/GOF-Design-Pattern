// The Visitor Interface declares a set of visiting methods that correspond
// to component classes. The signature of a visiting method allows the
// visitor to identify the exact class of the component that it's dealing
// with.
public interface IVisitor
{
	void VisitConcreteComponentA(ConcreteComponentA element);

	void VisitConcreteComponentB(ConcreteComponentB element);
}

// Concrete Visitors implement several versions of the same algorithm, which
// can work with all concrete component classes.
//
// You can experience the biggest benefit of the Visitor pattern when using
// it with a complex object structure, such as a Composite tree. In this
// case, it might be helpful to store some intermediate state of the
// algorithm while executing visitor's methods over various objects of the
// structure.
class ConcreteVisitor1 : IVisitor
{
	public void VisitConcreteComponentA(ConcreteComponentA element)
	{
		Console.WriteLine(element.ExclusiveMethodOfConcreteComponentA() + " + ConcreteVisitor1");
	}

	public void VisitConcreteComponentB(ConcreteComponentB element)
	{
		Console.WriteLine(element.SpecialMethodOfConcreteComponentB() + " + ConcreteVisitor1");
	}
}

class ConcreteVisitor2 : IVisitor
{
	public void VisitConcreteComponentA(ConcreteComponentA element)
	{
		Console.WriteLine(element.ExclusiveMethodOfConcreteComponentA() + " + ConcreteVisitor2");
	}

	public void VisitConcreteComponentB(ConcreteComponentB element)
	{
		Console.WriteLine(element.SpecialMethodOfConcreteComponentB() + " + ConcreteVisitor2");
	}
}