#include <iostream>
using namespace std;
class Simple {
public:
	Simple() { cout << "Simple Constructor Called" << endl; }
	~Simple() { cout << "Simple Destructor Called" << endl; }
};
unique_ptr<Simple> create() {
	auto ptr = make_unique<Simple>();
	return ptr;
}
int main(void) {
	unique_ptr<Simple> mySmartPtr1 = create();
	auto mySmartPtr2 = create();
	return 0;
}