#include <iostream>
#include <complex>
#include <chrono>
using namespace std::string_literals;
using namespace std::string_view_literals;
using namespace std::chrono_literals;
std::complex<long double> operator"" _i(long double d){
    return std::complex<long double>(0, d);
}
int main(void){
    std::complex<long double> c1 = 9.634_i;
    auto c2 = 1.23_i;
    const char* s1 = "Hello World";
    std::string s2 = "Hello World"s ;
    std::string_view s3 = "Hello World"sv;
    
    auto myDuration = 42min;
    
}