#include <iostream>
[[noreturn]] void forceProgramTermination(void){
    std::exit(1);
}
bool isDongleAvailable(void){
    bool isAvailable = false;
    return isAvailable;
}
bool isFeatureLicensed(int featureId){
    if(!isDongleAvailable())
        forceProgramTermination();
    else{
        bool isLicensed = false;
        return isLicensed;
    }
}
int main(void){
    bool isLicensed = isFeatureLicensed(42);
}