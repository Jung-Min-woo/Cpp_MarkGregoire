#include <iostream>
using namespace std;
class Simple {
public:
	Simple() { cout << "Simple Constructor Called" << endl; }
	void go(void) {}
	~Simple() { cout << "Simple Destructor Called" << endl; }
};
void useResource(weak_ptr<Simple>& weakSimple) {
	auto resource = weakSimple.lock();
	if (resource)
		cout << "Resource still alive." << endl;
	else
		cout << "Resource has been freed!" << endl;
}
int main(void) {
	auto sharedSimple = make_shared<Simple>();
	weak_ptr<Simple> weakSimple(sharedSimple);

	//weak_ptr
	useResource(weakSimple);

	//reset shared_ptr
	//Simple 리소스에 대한 shared_ptr는 하나뿐이므로
	//weak_ptr가 살아 있더라도 리소스가 해체된다. 
	sharedSimple.reset();
	//weak_ptr를 한 번 더 사용한다.
	useResource(weakSimple);
	return 0;
}