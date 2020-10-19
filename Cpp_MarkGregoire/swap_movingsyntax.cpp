#include <iostream>
using namespace std;
template <typename T>
void swapCopy(T& a, T& b) {
	T temp(a);
	a = b; // a�� temp�� �����ϰ�, b�� a�� ����, temp�� a�� ����
	b = temp;
}
template <typename T>
void swapMove(T& a, T& b) {
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}