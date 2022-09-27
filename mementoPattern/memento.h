#pragma once
#include <string>

using namespace std;

class Memento
{
public:
	Memento(string state) : _state(state){};

	string GetState() const;

private:
	string _state;
};
