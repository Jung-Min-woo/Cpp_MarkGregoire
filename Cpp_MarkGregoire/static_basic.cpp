#include <iostream>
using namespace std;
void performTask(){
    static bool initialized = false;
    if(!initialized){
        cout<<"Initialized"<<endl;
        initialized = true;
    }
}
// Initialization orders of nonlocal variables
// Demo::x -> y // there is no standard order
class Demo{
    public: static int x;
};
int Demo::x = 3;
int y = 4; 
int main(void){
    performTask();
    performTask();
    return 0;
}