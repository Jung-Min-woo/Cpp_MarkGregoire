#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//c style string
char* copyString(const char* str) {
	char* result = new char[strlen(str) + 1];
	strcpy(result, str);
	return result;
}
char* appendStrings(const char* str1, const char* str2, const char* str3) {
	char* result = new char[strlen(str1) + strlen(str2) + strlen(str3) + 1];
	strcpy(result, str1);
	strcat(result, str2);
	strcat(result, str3);
	return result;
}
int main(void) {
	//c style string
	char text1[] = "abcdef";
	size_t s1 = sizeof(text1); //7
	size_t s2 = strlen(text1); //6
	const char* text2 = "abcdef";
	size_t s3 = sizeof(text2); // usually 4byte (pointer)
	size_t s4 = strlen(text2); //6
	std::cout << s1 << " " << s2 << " " << s3 << " " << s4 << std::endl;
	//raw literal string
	const char* text3 = "Hello World";
	const char* text4 = "Hello \"World\"!";
	const char* text5 = R"(Hello "World"!)";
	const char* text6 = R"-( "((Hello))" fdff)-";
	std::cout << text3 << text4 << text5 << endl;
	std::cout << text6 << endl;
}