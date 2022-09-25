using System.Collections;

abstract class IteratorAggregate : IEnumerable
{
	// Returns an Iterator or another IteratorAggregate for the implementing
	// object.
	public abstract IEnumerator GetEnumerator();
}

// Concrete Collections provide one or several methods for retrieving fresh
// iterator instances, compatible with the collection class.
class WordsCollection : IteratorAggregate
{
	List<string> _collection = new List<string>();

	string _direction = "asc";

	public void ReverseDirection()
	{
		this._direction = this._direction == "asc" ? "desc" : "asc";
	}

	public List<string> getItems()
	{
		return _collection;
	}

	public void AddItem(string item)
	{
		this._collection.Add(item);
	}

	// In Csharp, we can override GetEnumerator() to define custom iterator
	public override IEnumerator GetEnumerator()
	{
		bool isReverseOrder = this._direction == "desc";
		return new AlphabeticalOrderIterator(this, isReverseOrder);
	}
}