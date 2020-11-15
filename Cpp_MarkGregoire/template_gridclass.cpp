#include <iostream>
#include <optional>
template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid{
    public:
        Grid() = default;
        virtual ~Grid() = default;
        Grid(const Grid& src) = default;
        Grid<T, WIDTH,  HEIGHT>& operator=(const Grid& rhs) = default;
        std::optional<T>& at(size_t x, size_t y);
        const std::optional<T>& at(size_t x, size_t y) const;

        size_t getHeight() const {return HEIGHT;}
        size_t getWidth() const{return WIDTH;}
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::optional<T> mCells[WIDTH][HEIGHT];
};
template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const{
    if(x>=WIDTH||y>=HEIGHT)
        throw std::out_of_range("");
}
template <typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const{
    verifyCoordinate(x, y);
    return mCells[x][y];
}
template <typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y){
    return const_cast<std::optional<T>&>(std::as_const(*this).at(x,y));
}
int main(void){
    Grid<int, 10,10> myGrid;
    Grid<int, 10, 10> anotherGrid;
    myGrid.at(2,3) = 42;
    anotherGrid = myGrid;
    std::cout<<anotherGrid.at(2,3).value_or(0);
    //ERROR 
    // size_t height = 10;
    // Grid<int, 10, height> testGrid;
}