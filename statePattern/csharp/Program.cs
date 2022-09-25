namespace StatePattern
{
	class Program
	{
		static void Main(string[] args)
		{
			var context = new Context(new ConcreteStateA());
			context.Request1();
			context.Request2();
		}
	}
}

// Context: Transition state to ConcreteStateA.

// ConcreteStateA handles request1.
// ConcreteStateA wants to change the state of the context.
// Context: Transition state to ConcreteStateB.

// ConcreteStateB handles request2.
// ConcreteStateB wants to change the state of the context.
// Context: Transition state to ConcreteStateA.