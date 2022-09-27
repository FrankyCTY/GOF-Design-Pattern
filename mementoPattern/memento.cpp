#include "./memento.h"
#include <string>

string Memento::GetSnapshot() const
{
	return _state;
}