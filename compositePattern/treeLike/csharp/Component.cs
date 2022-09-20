abstract class Component
{
	protected Component? _parent;

	public virtual void Add(Component component)
	{
		throw new NotImplementedException();
	}
	public virtual void Remove(Component component)
	{
		throw new NotImplementedException();
	}
	public virtual bool IsComposite()
	{
		return false;
	}
	public virtual void SetParent(Component parent)
	{
		_parent = parent;
	}

	public virtual Component? GetParent()
	{
		return _parent;
	}

	public abstract string Operation();
}