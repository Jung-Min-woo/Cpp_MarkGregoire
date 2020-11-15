#include <iostream>
#define SQUARE(x) ((x)*(x))
//use inline function instead use MACRO
//ex1) cout<<SQUARE(veryExpensiveFunctionCallToComputeNumbr()))
// --> makes compute twice works
using namespace std;
int main(void){
    cout<<SQUARE(5)<<endl;
    return 0;
}