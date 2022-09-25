#include "./aggregate.h"
#include "./iterator.h"

using namespace std;

void WordsAggregate::Add(string newWord)
{
	_words.push_back(newWord);
	_size++;
}

string WordsAggregate::GetItem(int position) const
{
	return _words[position];
}

int WordsAggregate::GetSize() const
{
	return _size;
}

Iterator *WordsAggregate::CreateIterator()
{
	return new Iterator(this);
}