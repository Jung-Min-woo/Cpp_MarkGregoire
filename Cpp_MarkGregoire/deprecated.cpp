#include<iostream>
[[deprecated("Unsafe method, please use xyz")]] void func() {}
int main(void){
    func(); //warning: 'void func()' is deprecated: Unsafe method, please use xyz;
}  