#include <iostream>
using namespace std;
enum PieceType1 { PieceTypeKing = 1, PieceTypeQueen, PieceTypeRook = 10, PieceTypePawn};
enum class PieceType2 { King = 1, Queen, Rook = 10, Pawn};
enum class PieceType3 :unsigned long { King = 1, Queen, Rook = 10, Pawn};
int main(void) {
	cout << "Default : "<<PieceTypeKing << endl;
	cout << "Default : "<<PieceTypeQueen << endl;
	cout << "Default : "<<PieceTypePawn << endl;
	cout << "PieceType2(strongly typed) : " << static_cast<int>(PieceType2::King) << endl;  // use static_cast<> to invert <PieceType2> -> <integer>
	return 0;
}