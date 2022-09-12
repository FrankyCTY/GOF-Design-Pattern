#pragma once
#include "./common.h"

// Strategy
class Compositor
{
public:
	virtual int Compose(
			Coord natural[], Coord stretch[], Coord shrink[],
			int componentCount, int lineWidth, int breaks[]) = 0;

protected:
	Compositor();
};

// Concrete Strategy 1
class SimpleCompositor : public Compositor
{
public:
	SimpleCompositor();
	int Compose(
			Coord natural[], Coord stretch[], Coord shrink[],
			int componentCount, int lineWidth, int breaks[]);
};

// Concrete Strategy 2
class TeXCompositor : public Compositor
{
public:
	TeXCompositor();
	int Compose(
			Coord natural[], Coord stretch[], Coord shrinkf[],
			int componentCount, int lineWidth, int breaks[]);
};

// Concrete Strategy 3
class ArrayCompositor : public Compositor
{
public:
	ArrayCompositor(int interval);
	int Compose(
			Coord natural[], Coord stretch[], Coord shrink[],
			int componentCount, int lineWidth, int breaks[]);
};