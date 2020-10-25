#include <iostream>
using namespace std;
class Base {
public:
	Base() {}
	~Base() {}
};
class Derived : private Base {
public:
	Derived() {
		mString = new char[30];
		cout << "mString allocated" << endl;
	}
	~Derived() {
		delete[] mString;
		cout << "mString deallocated" << endl;
	}
private:
	char* mString;
};
int main(void) {
	//ERR: Base* ptr = new Derived();
	//ERR: delete ptr;
	return 0;
}