#include <vector>

class Document
{
public:
	void Open();
	void Save();
	void Close();
	void DoRead();
};

class Docs
{
public:
	std::vector<Document *> docs;
	void AddDocument(Document *doc)
	{
		docs.push_back(doc);
	}
};

class Application
{

public:
	Docs *_docs = new Docs();
	// Template Method
	void OpenDocument(const char *name);
	// Primitive operations - Has to be overridden (etc. abstract operations)
	bool CanOpenDocument(const char *name);
	// Factory Method
	Document *DoCreateDocument();
	// Primitive operations - Has to be overridden (etc. abstract operations)
	void AboutToOpenDocument(Document *doc);
};

// Invariants encapsulated
void Application::OpenDocument(const char *name)
{
	if (!CanOpenDocument(name))
	{
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