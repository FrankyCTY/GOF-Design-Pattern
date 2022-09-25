#include "./iterator.h"

using namespace std;

int Iterator::GetElementPosition() const
{
	return _position;
}

void Iterator::SetElementPosition(int newPosition)
{
	bool isInvalidPosition = newPosition > _wordsAggregate->GetSize() - 1;
	if (isInvalidPosition)
	{
		printf("Invalid new position %d\n", newPosition);
		return;
	}

	_position = newPosition;
}

string Iterator::Current() const
{
	return _wordsAggregate->GetItem(GetElementPosition());
}

void Iterator::Next()
{
	_position++;
}

bool Iterator::IsTraversalDone()
{
	int totalWords = _wordsAggregate->GetSize();
	return _position > totalWords - 1;
}