#include <iostream>
using namespace std;
int main(void){
    //ex1 change main ref.
    int x = 3, z=5;
    int& xRef = x;
    int& zRef = z;
    zRef = xRef;
    cout<<"x is "<<x<<endl;
    cout<<"z is"<<z<<endl;
    
    //ex2 pointer reference
    int* intP;
    int*& ptrRef = intP;
    ptrRef = new int;
    *ptrRef = 5;

    int x2 = 3;
    int& xRef2 = x2;
    int* xPtr= &xRef2;
    *xPtr = 100;
}