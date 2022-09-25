abstract class State
{
	protected Context? _context;

	public void SetContext(Context context)
	{
		this._context = context;
	}

	public abstract void Handle1();

	public abstract void Handle2();
}

// Concrete States implement various behaviors, associated with a state of
// the Context.
class ConcreteStateA : State
{
	public override void Handle1()
	{
		Console.WriteLine("ConcreteStateA handles request1.");
		Console.WriteLine("ConcreteStateA wants to change the state of the context.");
		this?._context?.TransitionState(new ConcreteStateB());
	}

	public override void Handle2()
	{
		Console.WriteLine("ConcreteStateA handles request2.");
	}
}

class ConcreteStateB : State
{
	public override void Handle1()
	{
		Console.Write("ConcreteStateB handles request1.");
	}

	public override void Handle2()
	{
		Console.WriteLine("ConcreteStateB handles request2.");
		Console.WriteLine("ConcreteStateB wants to change the state of the context.");
		this?._context?.TransitionState(new ConcreteStateA());
	}
}
