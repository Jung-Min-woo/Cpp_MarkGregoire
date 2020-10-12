#include <iostream>
using namespace std;
class Simple {
public:
	Simple() { cout << "Simple Constructor Called" << endl; }
	void go(void) {}
	~Simple() { cout << "Simple Destructor Called" << endl; }
};
class Foo {
public:
	Foo(unique_ptr<int> data) :mData(move(data)) {}
private:
	unique_ptr<int> mData;
};
void leaky(void){
	Simple* mySimplePtr = new Simple(); // Memory leaks
	mySimplePtr->go();
}
void couldBeLeaky(void) {
	Simple* mySimplePtr = new Simple();
	mySimplePtr->go(); // If exception called, memory leaks
	delete mySimplePtr;
}
void notLeaky() {
	auto mySimplePtr = make_unique<Simple>();
	mySimplePtr->go();
	//if ur complier does not support make_unique();
	unique_ptr<Simple> mySimplePtr_unique(new Simple());
	//C++17 ~ 
	// 1. foo(unique_ptr<Simple>(new Simple()), unique_ptr<Bar>(new Bar(data())));
	// 2. foo(make_unique<Simple>(), make_unique<Bar>(data()))
}
void processData(Simple* simple) {return;}
//custrom deleter
int* malloc_int(int value) {
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}
int main(void) {
	//create unique_ptr
	auto mySimpleSmartPtr = make_unique<Simple>();
	processData(mySimpleSmartPtr.get());
	mySimpleSmartPtr.reset(); // 리소스 해제 후 nullptr 초기화
	mySimpleSmartPtr.reset(new Simple()); //리소스 해제 후 새로운 Simple 인스턴스로 설정
	Simple* simple = mySimpleSmartPtr.release(); // 소유권 해제;
	delete simple;
	simple = nullptr;
	
	auto myIntSmartPtr = make_unique <int>(42); 
	Foo f(move(myIntSmartPtr)); //std::move 소유권 이동

	//C style Array 
	auto myVariableSizedArray = make_unique<int[]>(10); //but std::array or std::vector recommended
	
	//custom deleter
	unique_ptr<int, decltype(free)*> myIntSmartPtr2(malloc_int(42), free);
	return 0;
}