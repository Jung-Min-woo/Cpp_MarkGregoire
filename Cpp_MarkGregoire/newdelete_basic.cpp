#include<iostream>
using namespace std;
char** allocateCharacterBoard(size_t xDimension, size_t yDimension) {
	char** myArray = new char* [xDimension];
	for (size_t i = 0; i < xDimension; i++)
		myArray[i] = new char[yDimension];
	return myArray;
}
void releaseCharacterBoard(char** myArray, size_t xDimension) {
	for (size_t i = 0; i < xDimension; i++)
		delete myArray[i];
	delete[] myArray;
}
class Simple {
public:
	Simple() { cout << "Simple Constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};
int main(void) {
	/*ex1*/
	//Simple* mySimpleArray = new Simple[4];
	//delete[] mySimpleArray;
	//mySimpleArray = nullptr;

	/*ex2*/
	const size_t size = 4;
	Simple** mySimplePtrArray = new Simple * [size];
	for (size_t i = 0; i < size; i++)
		mySimplePtrArray[i] = new Simple();
	for (size_t i = 0; i < size; i++)
		delete mySimplePtrArray[i];
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;
}