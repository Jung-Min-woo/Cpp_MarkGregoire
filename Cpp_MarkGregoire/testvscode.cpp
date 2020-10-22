#include <iostream>
#include <string>
#include <string_view>

using namespace std;
int main(void){
    std::string s1 = "HEEL";
    std::string_view s2("Hello");
    std::cout<<s1<<std::endl;
    return 0;
}