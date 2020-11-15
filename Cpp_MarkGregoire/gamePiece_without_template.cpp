
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
        GameBoard(const GameBoard& src); // copy ctor
        virtual ~GameBoard() = default; // virtual default detor
        GameBoard& operator=(const GameBoard& rhs); // operator=
        
        //Make move ctor, operator= default; 
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
GameBoard::GameBoard(size_t width, size_t height) : mWidth(width), mHeight(height){
    mCells.resize(mWidth);
    for( auto& column : mCells)
        column.resize(mHeight);
}
GameBoard::GameBoard(const GameBoard& src) 
    : GameBoard(src.mWidth, src.mHeight){
        for(size_t i =0; i<mWidth; i++)
            for(size_t j = 0; j<mHeight; j++)
                if(src.mCells[i][j])
                    mCells[i][j] = src.mCells[i][j]->clone();
    }
void GameBoard::verifyCoordinate(size_t x, size_t y) const{
    if(x>= mWidth || y>= mHeight)
        throw std::out_of_range("");
}
void swap(GameBoard& first, GameBoard& second) noexcept{
    using std::swap;
    swap(first.mWidth, second.mWidth);
    swap(first.mHeight, second.mHeight);
    swap(first.mCells, second.mCells);
}
GameBoard& GameBoard::operator=(const GameBoard& rhs){
    if(this == &rhs)
        return *this;
    GameBoard temp(rhs);
    swap(*this, temp);
    return *this;
}
const unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const{
    verifyCoordinate(x, y);
    return mCells[x][y];
}
unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y){
    return const_cast<unique_ptr<GamePiece>&>(as_const(*this).at(x,y));
}
//ex
class TicTacToePiece : public GamePiece{
    public:
        virtual std::unique_pt<GamePiece> clone() const override;
};
std::unique_ptr<GamePiece> TicTacToePiece::clone()  const{
    return std::make_unique<TicTacToePiece>(*this);
}
int main(void){
    GameBoard chessBoard(8,8);
    auto pawn = std::make_unique<ChessPiece>();
    chessBoard.at(0,0) = std::move(pawn);
    chessBoard.at(0,1) = std::make_unique<ChessPiece>();
    chessBoard.at(0,1) = nullptr;
    //!!!cause trouble!!!
    //chessBoard.at(0,1) = make_unique<TicTacToePiece>();
    return 0;
}