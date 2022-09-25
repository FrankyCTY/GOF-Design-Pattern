#pragma once
#include <string>
#include "./aggregate.h"

using namespace std;

class Iterator
{
public:
	Iterator(Aggregate *wordsAggregate) : _position(0), _wordsAggregate(wordsAggregate){};

	int GetElementPosition() const;

	void SetElementPosition(int newPosition);

	// Get current element
	string Current() const;

	void Next();

	bool IsTraversalDone();

private:
	int _position;
	Aggregate *_wordsAggregate;
};