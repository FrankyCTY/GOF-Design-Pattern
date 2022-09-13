#include <iostream>
#include "component.h"
#include "decorator.h"

// Class depends on Component
class Window
{
public:
	void SetContents(VisualComponent *contents)
	{
		contents->Draw();
	};
};

int main()
{
	Window *window = new Window;
	window->SetContents(new BorderDecorator(new ScrollbarDecorator(new TextView), 10));

	return 0;
}