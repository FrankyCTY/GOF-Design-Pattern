abstract class Equipment
{
	protected string _name;

	public Equipment()
	{
		_name = "Equipment";
	}

	public virtual void Add(Equipment component)
	{
		throw new NotImplementedException();
	}
	public virtual void Remove(Equipment component)
	{
		throw new NotImplementedException();
	}

	public virtual string GetName()
	{
		return _name;
	}

	public abstract int Power();
	public abstract int NetPrice();
}