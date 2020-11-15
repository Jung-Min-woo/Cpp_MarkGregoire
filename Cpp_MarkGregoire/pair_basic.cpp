#include <iostream>
#include <utility>
#include <string>
template<typename T>
class SpreadsheetCell{
    public:
        SpreadsheetCell(const T& t) : mContent(t) {}
        const T& getContent() const{return mContent;}
    private:
        T mContent;
};
SpreadsheetCell(const char*) -> SpreadsheetCell<std::string>;
int main(void){
    std::pair<int, double> pair1(1,2.3);
    auto pair2 = std::make_pair(1, 2.3);
    std::pair pair3(1, 2.3);

    std::string myString = "Hello World!";
    SpreadsheetCell cell(myString);
}