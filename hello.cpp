#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
	Parent()
	{
		cout << "Parent constructor" << endl;
	};

	Parent(const Parent &parent)
	{
		cout << "Parent Copy Constructor" << endl;
	};

	Parent &operator=(const Parent &rhs)
	{
		cout << "Parent Copy Assignment Operator" << endl;
		return *this;
	};
};

class Child : public Parent
{
public:
	Child(const string name) : _name(name)
	{
		cout << "Child Constructor" << endl;
	};

	// Compiler will call default constructor but not calling parent copy constructor
	// Because we are not explicit deciding which member function to call in member initialization list
	Child(const Child &child)
	{
		cout << "Child Copy Constructor" << endl;
		_name = child._name;
	};

	Child &operator=(const Child &rhs)
	{
		cout << "Child Copy Assignment Operator" << endl;
		_name = rhs._name;
		return *this;
	};

	~Child()
	{
		cout << "Child Destructor" << endl;
	};

	string GetName() const
	{
		return _name;
	}

private:
	string _name;
};

string &work(string &str)
{
	return str;
};

const int add(int a, int b) { return a + b; }

int main()
{
	int a, b;
	cin >> a >> b;
	int result = add(a, b);
	result = 20;
	cout << result << endl;
	return 0;
};