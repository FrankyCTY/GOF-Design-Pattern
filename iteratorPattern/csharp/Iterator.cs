using System.Collections;

// Implement on top of the base iterator interface
abstract class Iterator : IEnumerator
{
	object IEnumerator.Current => GetCurrentElement();

	// Returns the key of the current element
	public abstract int GetCurrentPosition();

	// Returns the current element
	public abstract object GetCurrentElement();

	// Move forward to next element
	public abstract bool MoveNext();

	// Rewinds the Iterator to the first element
	public abstract void Reset();
}

// Concrete Iterators implement various traversal algorithms. These classes
// store the current traversal position at all times.
class AlphabeticalOrderIterator : Iterator
{
	private WordsCollection _collection;
	// Stores the current traversal position. An iterator may have a lot of
	// other fields for storing iteration state, especially when it is
	// supposed to work with a particular kind of collection.
	private int _position = -1;
	private bool _reverse = false;
	public AlphabeticalOrderIterator(WordsCollection collection, bool reverse = false)
	{
		this._collection = collection;
		this._reverse = reverse;

		if (reverse)
		{
			this._position = collection.getItems().Count;
		}
	}

	public override object GetCurrentElement()
	{
		return this._collection.getItems()[this.GetCurrentPosition()];
	}

	public override int GetCurrentPosition()
	{
		return this._position;
	}

	public override bool MoveNext()
	{
		int updatedPosition = this._position + (this._reverse ? -1 : 1);

		if (updatedPosition >= 0 && updatedPosition < this._collection.getItems().Count)
		{
			this._position = updatedPosition;
			return true;
		}
		else
		{
			return false;
		}
	}

	public override void Reset()
	{
		this._position = this._reverse ? this._collection.getItems().Count - 1 : 0;
	}
}