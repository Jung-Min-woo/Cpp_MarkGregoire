#include <iostream>
using namespace std;

class Something {
public:
	Something() { cout << "2"; }
};
class Base {
public:
	Base() { cout << "1";}
};
class Derived : public Base {
public:
	Derived() { cout << "3"; }
private:
	Something mDataMember;
};
int main(void) {
	Derived myDerived; //Print 123
	return 0;
}