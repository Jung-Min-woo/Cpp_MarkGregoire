#include <iostream>
#include <string>
#include <utility>
//ex1 const_char()
//extern void ThirdPartyLibraryMethod(char* str);
//void f(const char* str){
//    ThirdPartyLibraryMethod(const_cast<char*>(str));
//}
//ex3 static_cast(downcasting)
class Base{
    public:
        virtual ~Base() = default;
};
class Derived:public Base{
    public:
        virtual ~Derived() = default;
};
int main(void){
    //ex1 as_const #include<utility>
    std::string str = "C++";
    const std::string& constStr = std::as_const(str);
    //ex2 static_cast()
    int i = 3;
    int j = 4;
    double result = static_cast<double>(i) /j;
    //ex3 static_cast(downcasting)
    Base* b;
    Derived* d = new Derived();
    b = d;
    d = static_cast<Derived*>(b);
    Base base;
    Derived derived;
    Base& br = derived;
    Derived& dr = static_cast<Derived&>(br);
    return 0;
}