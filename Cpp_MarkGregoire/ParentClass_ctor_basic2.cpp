#include <iostream>
using namespace std;

class Something {
public:
	Something() { cout << "2"; }
};
class Base {
public:
	Base(int i) {
		cout << "Base ctor : " << i << endl;
	}
};
class Derived : public Base {
public:
	Derived();
private:
	Something mDataMember;
};
Derived::Derived() :Base(7) { cout << "Derived Called" << endl; }
int main(void) {
	Derived myDerived; //Print 123
	return 0;
}