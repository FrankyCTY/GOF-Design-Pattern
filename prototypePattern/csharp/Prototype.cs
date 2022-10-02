public class Person
{
	public int Age;
	public DateTime BirthDate;
	public string Name;
	public IdInfo IdInfo;

	public Person(int age, DateTime birthDate, string name, IdInfo idInfo)
	{
		Age = age;
		BirthDate = birthDate;
		Name = name;
		IdInfo = idInfo;
	}

	public Person ShallowCopy()
	{
		return (Person)this.MemberwiseClone();
	}

	public Person DeepCopy()
	{
		Person clone = (Person)this.MemberwiseClone();
		clone.IdInfo = new IdInfo(IdInfo.IdNumber);
		clone.Name = Name;
		return clone;
	}
}

