#include <iostream>
using namespace std;

class Base {
public:
	virtual void someMethod() {
		cout << "This is Base's version of someMethod()" << endl;
	};
protected:
	int mProtectedInt;
private:
	int mPrivateInt;
};
class Derived final : public Base  {
public :
	virtual void someOtherMethod();
	virtual void someMethod() override;
};
void Derived::someMethod() {
	cout << "This is Derived's verion of someMethod()" << endl;
}
void Derived::someOtherMethod() {
	cout << "I can access base class data member mProtectedInt" << endl;
	cout << "Its value is " << mProtectedInt << endl;
	//COMPILE ERROR : cout << "The value of mPrivateInt : " << mPrivateInt << endl;
}
int main(void) {
	Derived myDerived;
	myDerived.someMethod();
	myDerived.someOtherMethod();

	Base myBase;
	myBase.someMethod();
	
	Base* base = new Derived();
	//COMPILE ERROR : base->someOtherMethod(); 
}