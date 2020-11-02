#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = default;
	Base() = default;
	Base(const Base& src);
};
Base::Base(const Base& src) {}
class Derived : public Base{
public:
	Derived() = default;
	Derived(const Derived& src);
};
Derived::Derived(const Derived& src) : Base(src) {}