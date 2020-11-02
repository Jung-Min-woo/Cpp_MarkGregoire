#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() = default;
	virtual void overload() { cout << "Base's overload()" << endl; }
	virtual void overload(int i) { cout << "Base's overload(int i)" << endl; }
};
class Derived : public Base {
public:
	using Base::overload;
	virtual void overload() override {
		cout << "Dervied's overload" << endl;
	}
};
class BaseStatic {
public:	
	static void beStatic() {
		cout << "BaseStatic Being Static" << endl;
	}
};
class DerivedStatic : public BaseStatic {
public:
	static void beStatic() {
		cout << "DerivedStatic keppin' it static" << endl;
	}
};
int main(void) {
	/*ex1*/
	//Different
	BaseStatic::beStatic();
	DerivedStatic::beStatic();
	/*ex2*/
	DerivedStatic myDerviedStatic;
	BaseStatic& ref = myDerviedStatic;
	myDerviedStatic.beStatic();
	ref.beStatic();
	/*ex3*/
	Derived myDerived;
	Base& ref2 = myDerived;
	ref2.overload(); //Call Derived
	ref2.overload(1); 

	myDerived.overload();
	myDerived.overload(1); // using Base::overload makes #46 Clear error
}