#include <iostream>
using namespace std;
class Base {
public:
	Base() { cout << "Base Called" << endl; }
	void go_base() {}
	virtual void go() const{ cout << "Go Base" << endl; }
	virtual ~Base() = default;
};
class Derived : public Base {
public:
	Derived() { cout << "Derived Called" << endl; }
	void go_derived() {}
	virtual void go() const override{cout<<"Go Derived"<<endl;}
	virtual ~Derived() {
		"Derived dtor Called";
	}
};
int main(void) {
	Derived myDerived;	
	Base myBase1 = myDerived;
	//upCasting
	Base& myBase2 = myDerived;
	myBase1.go(); //sliced --> Go Base
	myBase2.go(); //non-sliced --> Go Derived

	//DownCasting
	Base* myBase3 = new Base();
	Derived* myDerived2 = dynamic_cast<Derived*>(myBase3); //DO NOT USE staitc_cast
	if (myDerived2 != nullptr)
		cout << "NULLPTR :: DOWNCASTING" << endl;
}