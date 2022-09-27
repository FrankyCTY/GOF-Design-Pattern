#include "./originator.h"
#include "./careTaker.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	string originalState = "original state";
	Originator *originator = new Originator(originalState);

	CareTaker *careTaker = new CareTaker(originator);
	careTaker->Backup();
	careTaker->PrintSnapshotsInfo();

	printf("\nClient: Ready to perform operation on originator and save again\n\n");

	originator->BusinessOperation();
	careTaker->Backup();
	careTaker->PrintSnapshotsInfo();

	printf("\nClient: Ready to store last snapshot of originator\n\n");

	careTaker->Restore();
	careTaker->PrintSnapshotsInfo();

	delete originator;
	delete careTaker;
	return 0;
};

// CareTaker: Received request to back up originator
// Originator: Create snapshot
// CareTaker: Received request to print snapshots info
// 1. original state

// Client: Ready to perform operation on originator and save again

// Originator: Perform business operation
// CareTaker: Received request to back up originator
// Originator: Create snapshot
// CareTaker: Received request to print snapshots info
// 1. original state
// 2. original state+

// Client: Ready to store last snapshot of originator

// CareTaker: Received request to restore old snapshot for originator
// Originator: Load snapshot
// CareTaker: Received request to print snapshots info
// 1. original state