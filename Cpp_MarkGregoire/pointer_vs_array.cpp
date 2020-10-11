#include <iostream>
#include <array>
using namespace std;
void doubleInts(int* theArray, size_t size) {
	for (size_t i = 0; i < size; i++)
		theArray[i] *= 2;
}
int main(void) {
	size_t arrSize = 4;
	int* heapArray = new int[arrSize] {1, 5, 7, 8};
	doubleInts(heapArray, arrSize);
	delete[] heapArray;
	heapArray = nullptr;

	int stackArray[] = { 5, 7, 9, 11 };
	arrSize = std::size(stackArray); // C++17~ using <array>
	//arrSize = sizeof(stackArray) / sizeof(stackArray[0]) ; //before C++17
	doubleInts(stackArray, arrSize);
	doubleInts(&stackArray[0], arrSize);
}