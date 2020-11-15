#include <iostream>
using namespace std;
class TicTacToePiece : public GamePiece{
    public:
        virtual std::unique_pt<GamePiece> clone() const override;
};
std::unique_ptr<GamePiece> TicTacToePiece::clone()  const{
    return std::make_unique<TicTacToePiece>(*this);
}
int main(void){

}