#pragma once
#include "./strategy.h"

// Context
class Composition
{
public:
	Composition(Compositor *);
	void Repair();

private:
	// Link break strategy
	Compositor *_compositor;

	int _componentCount;
	int _lineWidth;
	int *_lineBreaks;
	int _lineCount;
};
