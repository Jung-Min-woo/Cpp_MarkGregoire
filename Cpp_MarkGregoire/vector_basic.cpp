#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main(void) {
	vector<int> myVector = { 11, 22 };
	myVector.push_back(33);
	myVector.push_back(44);
	cout << "1st element: " << myVector[0] << endl;

	//structured binding ex1
	array<int, 3> myArr= { 11,22,33 };
	auto [x, y, z] = myArr;
	cout << "x, y, z = " << x << y << z << endl;

	//structured binding ex2
	struct Point { double mX, mY, mZ; };
	Point point;
	point.mX = 1.0; point.mY = 2.0; point.mZ = 3.0;
	auto [x1, y1, z1] = point;
	cout << "x, y, z = " << x1 << y1 << z1 << endl;
}