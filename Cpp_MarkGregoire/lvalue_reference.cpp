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
	handleMessage(std::move(a)); // Call handleMessage(string&&) 
	
	//rvalue 
	// int& i = 2; //ERROR : const N Reference
	// int& j = a+b; //ERROR : TEMPORAY Object Reference
	int&& i = 2;
	int c = 2, d = 3;
	int&& j = c + d;
}