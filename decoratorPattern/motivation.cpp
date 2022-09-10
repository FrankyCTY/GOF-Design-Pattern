#include <iostream>

// Component
class VisualComponent
{
public:
	VisualComponent();
	virtual void Draw();
	virtual void Resize();
	// . . .
};

// Concrete Component
class TextView : public VisualComponent
{
	virtual void Draw();
};

void TextView::Draw()
{
	std::cout << "Drawing for TextView" << std::endl;
}

// Decorator
class Decorator : public VisualComponent
{
public:
	Decorator(VisualComponent *);
	virtual void Draw();
	virtual void Resize();
	// . . -
private:
	VisualComponent *_component;
};

void Decorator::Draw()
{
	_component->Draw();
}
void Decorator::Resize()
{
	_component->Resize();
}

class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent *, int borderWidth);
	virtual void Draw();

private:
	void DrawBorder(int);

private:
	int _width;
};

// Concrete Decorator
void BorderDecorator::Draw()
{
	Decorator::Draw();
	DrawBorder(_width);
}

class Window
{
public:
	Window(){};
	void Window::SetContents(VisualComponent *contents);
};

void Window::SetContents(VisualComponent *contents)
{
	// ...
}

int main()
{
	Window *window = new Window;
	TextView *textView = new TextView;
	window->SetContents(textView);

	// Use decorator to add border to text view
	TextView *textView2 = new TextView;
	VisualComponent *textViewWithBorder = new BorderDecorator(textView, 1);
	window->SetContents(textViewWithBorder);

	return 0;
}