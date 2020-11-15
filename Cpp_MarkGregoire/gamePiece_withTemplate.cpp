#include <iostream>
#include <optional>
#include <vector>
template <typename T>
class Grid{
    public:
        explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
        virtual ~ Grid() = default;

    Grid(const Grid& src) = default;
    Grid<T>& operator=(const Grid& rhs) = default;
    
    Grid(Grid&& src) = default;
    Grid<T>& operator=(Grid&& rhs) = default;
    
    std::optional<T>& at(size_t x, size_t y);
    const std::optional<T>& at(size_t x, size_t y) const;

    size_t getHeight() const { return mHeight;}
    size_t getWidth() const{ return mWidth;}

    static const size_t kDefaultHeight = 10;
    static const size_t kDefaultWidth = 10;
    
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::vector<std::vector<std::optional<T>>> mCells;
        size_t mWidth, mHeight;
};
int main(void){}