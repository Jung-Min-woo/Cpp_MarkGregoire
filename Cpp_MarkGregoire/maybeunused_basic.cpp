#include <iostream>
int func(int param1, [[maybe_unused]] int param2){
    return 42; //warning C4100 : 'param1' : unreferenced formal parameter
}
int main(void){
    
}