#include <iostream>
#include "SpreadsheetCell.h"
using namespace std;
int main(void) {
	//Stack Allocated
	SpreadsheetCell myCell(5), anotherCell(4);
	cout << "cell 1: " << myCell.getValue() << endl;
	cout << "cell 2: " << anotherCell.getValue() << endl;

	//Heap Allocated
	SpreadsheetCell* myCellp = new SpreadsheetCell(3.7);
	cout << "cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;
	delete myCellp;
	myCellp = nullptr;

	//Heap Allocated2
	auto myCellp2 = make_unique<SpreadsheetCell>(3.7);
	//or unique_ptr<SpreadsheetCell> myCellp(new SpreadsheetCell(data));
	cout << "cell 1: " << myCellp2->getValue() <<
		" " << myCellp2->getString() << endl;
}