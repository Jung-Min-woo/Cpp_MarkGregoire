#include <iostream>
using namespace std;
void func(char* str) { cout << "char* version" << endl; }
void func(int i) { cout << "int version" << endl; }
int main(void) {
	func(NULL); // nullptr vs NULL=0
	func(nullptr);
	//smart pointer
	
	return 0;
}