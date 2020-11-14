#include <iostream>
#include <complex>
std::complex<long double> operator"" _i(long double d){
    return std::complex<long double>(0, d);
}
int main(void){
    std::complex<long double> c1 = 9.634_i;
    auto c2 = 1.23_i;
}