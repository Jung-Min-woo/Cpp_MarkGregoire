#include "Spreadsheet.h"
#include <stdexcept>
Spreadsheet::Spreadsheet(size_t width, size_t height) : mWidth(width), mHeight(height) {
	mCells = new SpreadsheetCell * [mWidth];
	for (size_t i = 0; i < mWidth; i++)
		mCells[i] = new SpreadsheetCell[mHeight];
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : Spreadsheet(src.mWidth, src.mHeight)
{
	for (size_t i = 0; i < mWidth; i++)
		for (size_t j = 0; j < mHeight; j++)
			mCells[i][j] = src.mCells[i][j];
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs) return *this;
	//v1
	//memory release
	//for (size_t i = 0; i < mWidth; i++)
	//	delete[] mCells[i];
	//delete[] mCells;
	//mCells = nullptr;

	////new Alloc
	//mWidth = rhs.mWidth;
	//mHeight = rhs.mHeight;

	//mCells = new SpreadsheetCell * [mWidth];
	//for (size_t i = 0; i < mWidth; i++)
	//	mCells[i] = new SpreadsheetCell[mHeight];
	////deep copy
	//for (size_t i = 0; i < mWidth; i++)
	//	for (size_t j = 0; j < mHeight; j++)
	//		mCells[i][j] = rhs.mCells[i][j];
	//return *this;

	//v2
	if (this == &rhs)
		return *this;
	Spreadsheet temp(rhs);
	swap(*this, temp);
	return *this;
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i];
	delete[] mCells;
	mCells = nullptr;
}
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
	verifyCoordinate(x, y);
	mCells[x][y] = cell;
}
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight)
		throw std::out_of_range("");
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	using std::swap;
	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}
