#include <iostream>
#include <string>
using namespace std;
void swap(int& first, int& second){
    int temp = first;
    first = second;
    second = temp;
}
//ex6 lvalue reference
void handleMessage(std::string& message){
    cout<<"handleMessage with lvalue reference: "<<message<<endl;
}
void handleMessage2(std::string&& message){
    cout<<"handleMessage with rvalue reference: "<<message<<endl;
}
//In Cstyle
void seperateOddsAndEvens(const int arr[], size_t size, int** odds, size_t* numOdds, int** evens, size_t* numEvens) {
    cout << "seperateOddsAndEvend : Cstyle" << endl;
    *numOdds = *numEvens = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) ++(*numOdds);
        else ++(*numEvens);
    }
    *odds = new int[*numOdds];
    *evens = new int[*numEvens];

    size_t oddsPos = 0, evensPos = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 1)
            (*odds)[oddsPos++] = arr[i];
        else
            (*evens)[evensPos++] = arr[i];
    }
}
//In Cpp Style
void seperateOddsAndEvens(const int arr[], size_t size, int*& odds, size_t& numOdds, int*& evens, size_t& numEvens) {
    cout << "seperateOddsAndEvend : Cppstyle" << endl;
    numOdds = numEvens = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) ++numOdds;
        else ++numEvens;
    }
    odds = new int[numOdds];
    evens = new int[numEvens];

    size_t oddsPos = 0, evenPos = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) odds[oddsPos++] = arr[i];
        else evens[evenPos++] = arr[i];
    }
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


    //ex6 lvalue reference
    //ERROR : handleMessage("Hello World"); // literal is not LVALUE
    std::string a = "Hello ";
    std::string b = "World";
    //ERROR handleMessage(a+b); // temporary value is not LValue
    handleMessage(a);
    handleMessage2(a+b);

    //ex7 split Evens And Odds
    cout << "ex7 in c style" << endl;
    int unSplit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* oddNums = nullptr;
    int* evenNums = nullptr;
    size_t numOdds = 0, numEvens = 0;
    seperateOddsAndEvens(unSplit, std::size(unSplit), &oddNums, &numOdds, &evenNums, &numEvens);
;   cout << "nodd : "<< numOdds << endl;
    cout << "neven : " << numEvens << endl;
    seperateOddsAndEvens(unSplit, std::size(unSplit), oddNums, numOdds, evenNums, numEvens);
    cout << "Nodd : " << numOdds << endl;
    cout << "NEven : " << numEvens << endl;
    return 0;
}
