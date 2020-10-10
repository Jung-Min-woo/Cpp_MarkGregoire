#include <iostream>
#include <array>

using namespace std;
int main(void) {
	int myArray1[3];
	myArray1[0] = 0;
	myArray1[1] = 0;
	myArray1[2] = 0;
	int myArray2[3] = { 0 };  // Initialize all 0
	
	//C++17 std::size
	unsigned int arraySize = std::size(myArray1); 
	std::cout << "arr size(myarr1) : c++17 : " << arraySize <<"  / ~c++14 : " << sizeof(myArray1) / sizeof(myArray1[0]) << std::endl;

	//C++17 <array> 
	array<int, 3> arr = { 9, 8, 7 };
	cout << "Array size = " << arr.size() << endl;
	cout << "2nd Element = " << arr[1] << endl;
}