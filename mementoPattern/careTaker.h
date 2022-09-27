#pragma once
#include "./originator.h"
#include "./memento.h"
#include "./careTaker.h"
#include <iostream>
#include <vector>

using namespace std;

class CareTaker
{
public:
	CareTaker(Originator *originator) : _originator(originator), _snapshots(new vector<Memento *>()){};

	void Backup() const;

	void Restore();

	void PrintSnapshotsInfo() const;

private:
	Originator *_originator;
	vector<Memento *> *_snapshots;
};
