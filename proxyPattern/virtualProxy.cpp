#include "./subject.h"
#include "./proxy.h"

int main()
{
	char *imageFileName = "file name";
	// Virtual proxy control access to create expensive object (real subject)
	Graphic *virtualProxy = new ImageProxy(imageFileName);
}