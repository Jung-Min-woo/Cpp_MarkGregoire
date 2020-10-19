#include <iostream>
using namespace std;
template <typename T>
void swapCopy(T& a, T& b) {
	T temp(a);
	a = b; // a를 temp에 복제하고, b를 a에 복제, temp를 a에 복제
	b = temp;
}
template <typename T>
void swapMove(T& a, T& b) {
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}