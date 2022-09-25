#include <iostream>
#include "./aggregate.h"
#include "./iterator.h"

using namespace std;

int main()
{
	WordsAggregate *aggregate = new WordsAggregate();
	aggregate->Add("hello");
	aggregate->Add("world");

	Iterator *it = aggregate->CreateIterator();
	cout << "Current position " << it->GetElementPosition() << endl;
	cout << "Current element " << it->Current() << endl;
	cout << "Is Traversal Finished: " << it->IsTraversalDone() << "\n"
			 << endl;

	cout << "=========== Traversal Start ===========\n"
			 << endl;

	it->SetElementPosition(100);
	for (it->GetElementPosition(); !it->IsTraversalDone(); it->Next())
	{
		cout << it->GetElementPosition() << " " << it->Current() << endl;
	}

	return 0;
}