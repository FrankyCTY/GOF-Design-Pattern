class Composite : Component
{
	private List<Component> _children = new();

	public override void Add(Component component)
	{
		_children.Add(component);
	}

	public override void Remove(Component component)
	{
		_children.Remove(component);
	}


	public override bool IsComposite()
	{
		return true;
	}


	public override string Operation()
	{
		int i = 0;
		string result = "";

		foreach (var child in _children)
		{
			result += child.Operation();

			bool isLastChild = i == _children.Count - 1;
			if (!isLastChild)
			{
				result += "+";
			}

			i++;
		}

		return "Branch(" + result + ")";
	}

}