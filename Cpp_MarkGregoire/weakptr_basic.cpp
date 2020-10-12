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
	//Simple ���ҽ��� ���� shared_ptr�� �ϳ����̹Ƿ�
	//weak_ptr�� ��� �ִ��� ���ҽ��� ��ü�ȴ�. 
	sharedSimple.reset();
	//weak_ptr�� �� �� �� ����Ѵ�.
	useResource(weakSimple);
	return 0;
}