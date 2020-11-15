
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class GamePiece{
    public:
        virtual std::unique_ptr<GamePiece> clone() const = 0;
};
class ChessPiece : public GamePiece{
    public:
        virtual std::unique_ptr<GamePiece> clone() const override;
};
std::unique_ptr<GamePiece> ChessPiece::clone() const{
    //Call copy con -> copy this instance
    return std::make_unique<ChessPiece>(*this);
}
class GameBoard{
    public:
        explicit GameBoard(size_t width= kDefaultWidth, size_t height = kDefaultHeight);
        GameBoard(const GameBoard& src);
        virtual ~GameBoard() = default;
        GameBoard& operator=(const GameBoard& rhs);
        
        GameBoard(GameBoard&& src);
        GameBoard& operator=(GameBoard&& src) = default;
        
        std::unique_ptr<GamePiece>& at(size_t x, size_t y);
        const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

        size_t getHeight() {return mHeight;}
        size_t getWidth() {return mWidth;}

        static const size_t kDefaultWidth = 10;
        static const size_t kDefaultHeight = 10;

        friend void swap(GameBoard& first, GameBoard& second) noexcept;

    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
        size_t mWidth, mHeight;
};

int main(void){
    return 0;
}