class Coord
{
	friend Coord operator+(Coord &a, Coord &b)
	{
		return a + b;
	}
};

// Context
class Composition
{
public:
	Composition(Compositor *);
	void Repair();

private:
	// Link break strategy
	Compositor *_compositor;
	int _componentCount; // the number of components
	int _lineWidth;			 // the Composition's line width
	int *_lineBreaks;		 // the position of linebreaks
	// in components
	int _lineCount; // the number of lines
};

void Composition::Repair()
{
	Coord *natural;
	Coord *stretchability;
	Coord *shrinkability;
	int componentCount;
	int *breaks;
	// prepare the arrays with the desired component sizes
	// . . .
	// determine where the breaks are:
	int breakCount;
	breakCount = _compositor->Compose(
			natural, stretchability, shrinkability,
			componentCount, _lineWidth, breaks);
	// lay out components according to breaks
	// . .
};

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
	virtual int Compose(
			Coord natural[], Coord stretch[], Coord shrink[],
			int componentCount, int lineWidth, int breaks[]);
};

// Concrete Strategy 2
class TeXCompositor : public Compositor
{
public:
	TeXCompositor();
	virtual int Compose(
			Coord natural[], Coord stretch[], Coord shrinkf[],
			int componentCount, int lineWidth, int breaks[]);
};

// Concrete Strategy 3
class ArrayCompositor : public Compositor
{
public:
	ArrayCompositor(int interval);
	virtual int Compose(
			Coord natural[], Coord stretch[], Coord shrink[],
			int componentCount, int lineWidth, int breaks[]);
};

int main()
{
	Composition *quick = new Composition(new SimpleCompositor);
	Composition *slick = new Composition(new TeXCompositor);
	Composition *iconic = new Composition(new ArrayCompositor(100));

	return 0;
}