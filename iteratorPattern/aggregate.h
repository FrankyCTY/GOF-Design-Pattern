#pragma once
#include "./iterator.h"
#include <string>
#include <vector>

using namespace std;

class Aggregate
{
public:
	virtual void Add(string newItem) = 0;
	virtual string GetItem(int position) const = 0;
	virtual int GetSize() const = 0;
};

class WordsAggregate : public Aggregate
{
public:
	WordsAggregate() : _size(0){};

	void Add(string newWord);

	string GetItem(int position) const;

	int GetSize() const;

	Iterator *CreateIterator();

private:
	int _size;
	vector<string> _words;
};
