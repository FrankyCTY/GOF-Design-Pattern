#pragma once
#include "./memento.h"
#include <iostream>

using namespace std;

class Originator
{
public:
	Originator(string state) : _state(state){};

	Memento *CreateSnapshot();

	void LoadSnapshot(Memento *snapshot);

	void BusinessOperation();

private:
	string _state;
};
