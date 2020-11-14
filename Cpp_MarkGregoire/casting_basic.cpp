#include <iostream>
#include <string>
#include <utility>
//ex1 const_char()
//extern void ThirdPartyLibraryMethod(char* str);
//void f(const char* str){
//    ThirdPartyLibraryMethod(const_cast<char*>(str));
//}
//ex3 static_cast(downcasting)
using namespace std;
class Base{
    public:
        virtual ~Base() = default;
};
class Derived:public Base{
    public:
        virtual ~Derived() = default;
};
class X{};
class Y{};
int main(void){
    //instruction
    //const 속성 제거 : const_cast()
    //언어에서 허용하는 명시적 : static_cast()
    //사용자 정의 생성자나 변환 연산자에서 지원하는 명시적 변환 :static_cast()
    //서로 관련없는 타입의 객체끼리 변환 : impossible
    //same 상속 계층에 있는 클래스 타입의 객체 포인터 사이의 변환 : dynamic_cast() 권장, static_cast도 가능
    //same 상속 계층에 있는 클래스 타입의 객체 레퍼런스 사이의 변환 : dynamic_cast() 권장, static_cast도 가능
    //서로 관련 없는 타입의 포인터 사이 변환 : reinterpret_cast()
    //서로 관련 없는 타입의 레퍼런스 사이 변환 : reinterpret_cast()
    //함수 포인터 사이의 변환 : reinterpret_cast()

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
    //ex4 reinterpret_cast()
    X x;
    Y y;
    X* xp = &x;
    Y* yp = &y;
    xp = reinterpret_cast<X*>(yp);
    //no need to cast when X* -> void*
    void* p = xp;
    //use reinterpret_cast void* -> X*
    xp = reinterpret_cast<X*>(p);
    X& xr = x;
    Y& yr= reinterpret_cast<Y&>(x);
    //ex5
    Base* b2;
    Derived* d2;
    b2 = d2;
    d2 = dynamic_cast<Derived*>(b2);
    Base b3;
    Derived d3;
    Base& b4 = b3;
    try{
        Derived& dr = dynamic_cast<Derived&>(b4);
    }catch(const bad_cast&){
        cout<<"Bad cast"<<endl;
    }
    return 0;
}