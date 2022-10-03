public class Director
{
	private IBuilder _builder;

	public IBuilder Builder
	{
		set { _builder = value; }
	}

	public Director(IBuilder builder)
	{
		_builder = builder;
	}

	// The Director can construct several product variations using the same
	// building steps.
	public void BuildMinimalViableProduct()
	{
		this._builder.BuildPartA();
	}

	public void BuildFullFeaturedProduct()
	{
		this._builder.BuildPartA();
		this._builder.BuildPartB();
		this._builder.BuildPartC();
	}
}