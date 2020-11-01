#include <iostream>
#include <string>
using namespace std;
class Base{
    public:
        virtual ~Base() = default;
        Base() = default;
        Base(std::string_view str);
        Base(float f);
};
class Derived:public Base{
    public:
        using Base::Base;
        Derived(float f);
        Derived(int i);
};
/*ex2*/
class Base1{
    public:
        virtual ~Base1() = default;
        Base1() = default;
        Base1(float f);
};
class Base2{
    public:
        virtual ~Base2() = default;
        Base2() = default;
        Base2(std::string_view str);
        Base2(float f);
};
class Derived2 : public Base1, public Base2{
    public:
        using Base1::Base1;
        using Base2::Base2;
        //Dervied2(char c);
        Derived2(float f);
};
int main(void){
    Base base("hello");
    Derived derived1(1);
    //ERROR CALLED : Derived dervied2("Hello"); ++ Derived : using Base::Base;
    //Error Solved (LINE 13)
    Derived derived2("Derived2"); // Call Base(string_view)
    Derived derived3(1.23f); // Call Dervied(float) 
}