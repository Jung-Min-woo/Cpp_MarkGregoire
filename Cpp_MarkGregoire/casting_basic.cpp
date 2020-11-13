#include <iostream>
#include <string>
#include <utility>
//ex1 const_char()
//extern void ThirdPartyLibraryMethod(char* str);
//void f(const char* str){
//    ThirdPartyLibraryMethod(const_cast<char*>(str));
//}
int main(void){
    //ex1 as_const #include<utility>
    std::string str = "C++";
    const std::string& constStr = std::as_const(str);
    //ex2 static_cast()
    int i = 3;
    int j = 4;
    double result = static_cast<double>(i) /j;
}