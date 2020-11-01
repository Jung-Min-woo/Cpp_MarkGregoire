#include <iostream>
using namespace std;
class Base {
public:
	Base() { cout << "Base Called" << endl; }
	void go_base() {}
	virtual void go() const = 0; // Declare		Abstract Class 
	virtual ~Base() = default;
};
class Derived : public Base {
public:
	Derived() { cout << "Derived Called" << endl; }
	void go_derived() {}
	virtual void go() const override { cout << "Go Derived" << endl; }
	virtual ~Derived() {
		"Derived dtor Called";
	}
};