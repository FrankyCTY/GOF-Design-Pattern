#pragma once

class Application
{
public:
	void Add(Document *);
};

class Document
{
public:
	explicit Document(char *docName);

private:
	char *_docName;
};