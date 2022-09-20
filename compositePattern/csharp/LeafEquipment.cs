class Motherboard : Equipment
{
	public Motherboard()
	{
		_name = "Motherboard";
	}

	public override int NetPrice()
	{
		return 1000;
	}


	public override int Power()
	{
		return 500;
	}
}

class Cpu : Equipment
{
	public Cpu()
	{
		_name = "Cpu";
	}

	public override int NetPrice()
	{
		return 1000;
	}


	public override int Power()
	{
		return 500;
	}
}


class UselessEquipment : Equipment
{
	public UselessEquipment()
	{
		_name = "UselessEquipment";
	}

	public override int NetPrice()
	{
		return 1;
	}


	public override int Power()
	{
		return 10;
	}
}
