#include <iostream>
#include <string>
const std::string message = "Test";
const std::string& foo() { return message; }
int main(void) {
	//1. auto keyword
	auto x = 123;
	auto f1 = foo();
	const auto& f2 = foo(); // auto�� const���� ���������� ����.
	//2. decltype keyword
	decltype(x) y = 456; // decltype�� const���� �����´�.
	decltype(foo()) f3 = foo();
}