#include <vector>

class Document
{
public:
	void Open();
	void DoRead();
};

class Application
{

public:
	void OpenDocument(const char *name);
	bool CanOpenDocument(const char *name);
	Document *DoCreateDocument();
	void AboutToOpenDocument(Document *doc);
};

void Application::OpenDocument(const char *name)
{
	if (!CanOpenDocument(name))
	{
		// cannot handle this document
		return;
	}
	Document *doc = DoCreateDocument();
	if (doc)
	{
		_docs->AddDocument(doc);
		AboutToOpenDocument(doc);
		doc->Open();
		doc->DoRead();
	}
};