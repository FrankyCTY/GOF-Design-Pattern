#include "./originator.h"
#include "./memento.h"

Memento *Originator::CreateSnapshot()
{
	printf("Originator: Create snapshot\n");
	return new Memento(_state);
}

void Originator::LoadSnapshot(Memento *snapshot)
{
	printf("Originator: Load snapshot\n");
	_state = snapshot->GetState();
}

void Originator::BusinessOperation()
{
	printf("Originator: Perform business operation\n");
	_state.append("+");
}