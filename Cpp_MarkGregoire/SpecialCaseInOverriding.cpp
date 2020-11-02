#include <iostream>
using namespace std;

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
}