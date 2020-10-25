#include <iostream>
using namespace std;

class Base {
public:
	virtual void someMethod(double d) {
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
	//ex1
	virtual void someMethod(double d) override// override keyword keeps COMPILE ERR override;
};
void Derived::someMethod(double d) {
	cout << "This is Derived's verion of someMethod()" << endl;
}
void Derived::someOtherMethod() {
	cout << "I can access base class data member mProtectedInt" << endl;
	cout << "Its value is " << mProtectedInt << endl;
	//COMPILE ERROR : cout << "The value of mPrivateInt : " << mPrivateInt << endl;
}
int main(void) {
	Derived myderived;
	Base& ref = myderived;
	ref.someMethod(1.1); // Called Base version
	ref.someMethod(1); //Called Derived version
}