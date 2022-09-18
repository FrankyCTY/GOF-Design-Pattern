#pragma once
#include <iostream>
#include <list>
#include <string>
#include "./subject.h"

class IObserver
{
public:
	virtual ~IObserver();
	virtual void Update(const std::string &message_from_subject) = 0;
};

class Observer : public IObserver
{
public:
	Observer(Subject &subject);
	~Observer();

	void Update(const std::string &message_from_subject);
	void RemoveMeFromTheList();
	void PrintInfo();

private:
	std::string message_from_subject_;
	Subject &subject_;
	static int static_number_;
	int number_;
};