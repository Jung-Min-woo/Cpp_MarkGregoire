//uniform initialization은 narrowing을 방지가능하다.
#include <iostream>
struct CircleStruct {
	int x, y;
	double radius;
};
class CircleClass {
public:
	CircleClass(int x, int y, double radius) : mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;	
};
class MyClass {
public:
	MyClass() :mArray{ 0,1,2,3 } {} // initializer 
private:
	int mArray[4];
};
void func(int i) {}
int main(void) {
	CircleStruct myCircle1 = { 10, 10, 2.5 };
	CircleClass myCircle2(10, 10, 2.5);
	CircleStruct myCircle3 = { 10, 10, 2.5 };
	CircleClass myCircle4 = { 10, 10, 2.5 };
	
	CircleStruct myCircle5{ 10, 10, 2.5 }; // uniform initialization
	CircleClass myCircle6{ 10, 10, 2.5 }; // uniform initialization

	int a = 3;
	int b(3);
	int c = { 3 }; // uniform initialization
	int d{ 3 }; // uniform initialization
	int e{}; // uniform initialization to zero

	//int x = { 3.14 }; compile error caused by narrowing
	//func({ 3.14 });  compile error caused by narrowing

	int* pArray = new int[4]{ 0, 1, 2, 3 };

	//copy list initialization
	auto a = { 11 }; //initializer_list<int>
	auto b = { 11, 22 }; //initializer_list<int>
	//direct list initialization
	auto c{ 11 };  // C++11/14 : initiailzer_list<int> -> C++17 int
	//auto d{ 11, 22 }; // C++11/14 : initiailzer_list<int> -> C++17 Compile Error
}