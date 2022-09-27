#include "./memento.h"
#include <string>

string Memento::GetState() const
{
	return _state;
}