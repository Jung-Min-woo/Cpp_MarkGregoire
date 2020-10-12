#define _CRT_SECURE_NO_WARNINGS
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
	Foo(int value) : mData(value) {}
	int mData;
};
//custom deleter
int* malloc_int(int value) {
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}
void CloseFile(FILE* fileptr) {
	if (fileptr == nullptr) return;
	fclose(fileptr);
	cout << "File Closed" << endl;
}
void doubleDelete() {
	Simple* mySimple = new Simple();
	shared_ptr<Simple> smartPtr1(Simple);
	shared_ptr<Simple> smartPtr2(Simple);
}
void nodoubleDelete() {
	auto smartPtr1 = make_shared<Simple>();
	shared_ptr<Simple> smartPtr2(smartPtr1);
}
int main(void) {
	auto mySimpleSmartPtr = make_shared<Simple>();
	//custom deleter
	shared_ptr<int> myIntSmartPtr(malloc_int(42), free);

	FILE* f = fopen("data.txt", "w");
	shared_ptr<FILE> filePtr(f, CloseFile);
	if (filePtr == nullptr) 
		cerr << "Error opening file" << endl;
	else 
		cout << "File Opened." << endl;
	
	//reference counting
	cout << "---------------------" << endl;
	doubleDelete();
	cout << "---------------------" << endl;
	nodoubleDelete();
	cout << "---------------------" << endl;
	cout << "---------------------" << endl;
	auto foo = make_shared<Foo>(42);
	auto aliasing = shared_ptr<int>(foo, &foo->mData);

}