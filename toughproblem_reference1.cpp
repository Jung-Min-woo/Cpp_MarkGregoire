#include <iostream>
using namespace std;
void swap(int& first, int& second){
    int temp = first;
    first = second;
    second = temp;
}
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

    //ex3 Reference Data Member
    // class Myclass{
    //     public:
    //         MyClass(int& ref) : mRef(ref) {}
    //     private: int& mRef; // mRef is not initialized --> ERROR
    // }

    //ex4 Reference Parameter
    int x3 = 5, y3 = 6;
    swap(x3, y3);
    //swap(5, 6) ::ERROR! pass by non-const reference 
    cout<<"(x3,y3) = (" <<x3<<", "<<y3<<")"<<endl;

    //ex5 pass Pointer as Reference
    int x5 = 5, y5 = 6;
    int* xp = &x5, *yp = &y5;
    cout<<"BEFORE SWAP"<<endl;
    cout<<"(xp,yp) = (" <<*xp<<", "<<*yp<<")"<<endl;
    swap(*xp,*yp);
    cout<<"After SWAP"<<endl;
    cout<<"(xp,yp) = (" <<*xp<<", "<<*yp<<")"<<endl;
}
