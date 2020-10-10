#include <iostream>
#include <string>
const std::string message = "Test";
const std::string& foo() { return message; }
int main(void) {
	//1. auto keyword
	auto x = 123;
	auto f1 = foo();
	const auto& f2 = foo(); // auto는 const까지 가져오지는 못함.
	//2. decltype keyword
	decltype(x) y = 456; // decltype은 const까지 가져온다.
	decltype(foo()) f3 = foo();
}