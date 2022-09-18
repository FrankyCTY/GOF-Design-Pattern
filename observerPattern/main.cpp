#include "./subject.h"
#include "./observer.h"

/**
 * - Pull model observer pattern
 * - Attach subject is done in observer constructor
 * - Detach subject is done on observer method
 */

int main()
{
	Subject *subject = new Subject;
	Observer *observer1 = new Observer(*subject);
	Observer *observer2 = new Observer(*subject);
	Observer *observer3 = new Observer(*subject);
	Observer *observer4;
	Observer *observer5;

	subject->CreateMessage("Hello World! :D");
	observer3->RemoveMeFromTheList();

	subject->CreateMessage("The weather is hot today! :p");
	observer4 = new Observer(*subject);

	observer2->RemoveMeFromTheList();
	observer5 = new Observer(*subject);

	subject->CreateMessage("My new car is great! ;)");
	observer5->RemoveMeFromTheList();

	observer4->RemoveMeFromTheList();
	observer1->RemoveMeFromTheList();

	delete observer5;
	delete observer4;
	delete observer3;
	delete observer2;
	delete observer1;
	delete subject;
}