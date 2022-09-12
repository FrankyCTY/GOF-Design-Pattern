#include <iostream>
#include "component.h"
#include "decorator.h"

// Class depends on Component
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
	// Class depends on Component
	Window *window = new Window;
	VisualComponent *textView = new TextView;
	window->SetContents(textView);

	// Use decorator to add border to text view
	TextView *textView2 = new TextView;
	VisualComponent *textViewWithBorder = new BorderDecorator(textView, 1);
	window->SetContents(textViewWithBorder);

	return 0;
}