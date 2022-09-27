#include "./originator.h"
#include "./mediator.h"

Memento *Originator::CreateSnapshot()
{
	printf("Originator: Create snapshot\n");
	return new Memento(_state);
}

void Originator::LoadSnapshot(Memento *stateSnapshot)
{
	printf("Originator: Load snapshot\n");
	_state = stateSnapshot->GetSnapshot();
}

void Originator::BusinessOperation()
{
	printf("Originator: Perform business operation\n");
	_state.append("+");
}
