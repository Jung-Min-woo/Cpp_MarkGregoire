#include <iostream>

//ex2 constexpr keyword
const int getArraySize() {return 32;}
constexpr int getArraySize2() { return 32;}
class Rect{
    public: 
        constexpr Rect(size_t width, size_t height)
            :mWidth(width), mHeight(height){}
        constexpr size_t getArea() const{return mWidth* mHeight;}
    private:
        size_t mWidth, mHeight;
};
int main(void){
    //ex1
    int arr_test[getArraySize2()] ;
    constexpr Rect r(8,2);
    int myArray[r.getArea()]; // OK
    
}