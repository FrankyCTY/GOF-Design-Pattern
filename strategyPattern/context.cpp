#include "./context.h"

void Composition::Repair()
{
	Coord *natural;
	Coord *stretchability;
	Coord *shrinkability;

	int componentCount;
	int *breaks;
	// prepare the arrays with the desired component sizes
	int breakCount;
	breakCount = _compositor->Compose(
			natural, stretchability, shrinkability,
			componentCount, _lineWidth, breaks);
};