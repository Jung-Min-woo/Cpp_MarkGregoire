#include <iostream>
#include <string>
void handleMessage(std::string& message) {
	std::cout << "handleMessage with lvalue reference" << std::endl;
}
void handleMessage(std::string&& message) {
	std::cout << "handleMessage with rvalue reference" << std::endl;
}
int main(void) {
	std::string a = "Hello ";
	std::string b = "world";
	handleMessage(a);
	handleMessage(a + b);
}