#include <iostream>
using namespace std;

class Base {
public:
	virtual void func1() {}
	virtual void func2() {}
	void nonVirtualFunc() {}
};
class Derived : public Base {
public:
	virtual void func2() override {}
	void nonVirtualFunc() {}
};
int main(void) {
	Base myBase;
	Derived myDerived;
}