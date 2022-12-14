#pragma once
#include "./observer.h"

class ISubject
{
public:
	virtual ~ISubject(){};
	virtual void Attach(IObserver *observer) = 0;
	virtual void Detach(IObserver *observer) = 0;
	virtual void Notify() = 0;
};

class Subject : public ISubject
{
public:
	virtual ~Subject();

	/**
	 * The subscription management methods.
	 */
	void Attach(IObserver *observer);
	void Detach(IObserver *observer);
	void Notify();

	void CreateMessage(std::string message = "Empty");

	void HowManyObserver();

	/**
	 * Usually, the subscription logic is only a fraction of what a Subject can
	 * really do. Subjects commonly hold some important business logic, that
	 * triggers a notification method whenever something important is about to
	 * happen (or after it).
	 */
	void SomeBusinessLogic();

private:
	std::list<IObserver *> list_observer_;
	std::string message_;
};