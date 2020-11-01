#include <iostream>
using namespace std;
class Base {
public:
	Base() { cout << "Base Called" << endl; }
	void go_base() {}
	virtual void go() const { cout << "Go Base" << endl; }
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
class Derived2 {
public:
	Derived2() = default;
	Derived2(const Derived& dv1) {
		cout << "This is Converting Constructor" << endl;
	}
};
int main(void) {
	Derived2 dv2;
}