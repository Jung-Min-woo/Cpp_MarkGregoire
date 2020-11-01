#include <iostream>
using namespace std;

class Base {
public:
	virtual void SomeMethod() { cout << "Error Solved" << endl; }
};
class Derived :public Base {
public:
	/*Solver*/
	using Base::SomeMethod;
	virtual void SomeMethod(int i); //No Compile Error but, no override
	virtual void SomeOtherMethod() {}
};
void Derived::SomeMethod(int i) {
	cout << "This is Derived's verison of someMethod with argument " << i
		<< "." << endl;
}
int main(void) {
	Derived myDerived;
	//ERROR : myDerived.SomeMethod (HIDE PARENT METHOD)
	//ERROR SOLVED *Line 11
	myDerived.SomeMethod(1);
	myDerived.SomeMethod();
}