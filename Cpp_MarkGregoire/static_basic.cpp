#include <iostream>
using namespace std;
void performTask(){
    static bool initialized = false;
    if(!initialized){
        cout<<"Initialized"<<endl;
        initialized = true;
    }
}
class Demo{
    public: static int x;
}
int main(void){
    performTask();
    performTask();
    return 0;
}