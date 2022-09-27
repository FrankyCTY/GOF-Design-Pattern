#include "./careTaker.h"

using namespace std;

void CareTaker::Backup() const
{
	printf("CareTaker: Received request to back up originator\n");
	Memento *newSnapshot = _originator->CreateSnapshot();
	_snapshots->push_back(newSnapshot);
}

void CareTaker::Restore()
{
	printf("CareTaker: Received request to restore old snapshot for originator\n");
	if (_snapshots->empty())
	{
		printf("CareTaker: No snapshot found for originator to load\n");
		return;
	}

	vector<Memento *>::iterator it = _snapshots->end() - 1;

	Memento *lastSnapshot = *(_snapshots->end() - 1);
	_originator->LoadSnapshot(lastSnapshot);

	_snapshots->pop_back();
}

void CareTaker::PrintSnapshotsInfo() const
{
	printf("CareTaker: Received request to print snapshots info\n");

	vector<Memento *>::iterator it;
	int counter = 1;

	for (it = _snapshots->begin(); it < _snapshots->end(); it++)
	{
		cout << counter << ". " << (*it)->GetSnapshot() << endl;
		counter++;
	}
}
