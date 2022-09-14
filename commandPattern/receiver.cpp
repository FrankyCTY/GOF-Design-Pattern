#include <iostream>
#include "./receiver.h"

void Application::Add(Document *doc)
{
	std::cout << "Adding doc" << std::endl;
}

Document::Document(char *docName)
{
	_docName = docName;
}