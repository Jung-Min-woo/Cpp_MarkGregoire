#include "Spreadsheet.h"
#include <stdexcept>
#include <algorithm>
Spreadsheet::Spreadsheet(size_t width, size_t height, SpreadsheetApplication& theApp)
	: mId(sCounter++), mWidth(std::min(width, kMaxWidth)), mHeight(std::min(height, kMaxHeight))
	, mTheApp(theApp)
{
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

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept :Spreadsheet()
{
	swap(*this, src);
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
	Spreadsheet temp(std::move(rhs));
	swap(*this, temp);
	return *this;
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
const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}
SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<SpreadsheetCell&>(std::as_const(*this).getCellAt(x, y));
}
size_t Spreadsheet::getId() const
{
	return mId;
}
void Spreadsheet::cleanup() noexcept
{
	for (size_t i = 0; i < mWidth; i++)
		delete[] mCells[i];
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}
void Spreadsheet::moveFrom(Spreadsheet& src) noexcept
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;
	mCells = src.mCells;

	src.mWidth = 0;
	src.mHeight = 0;
	src.mCells = nullptr;
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

Spreadsheet::Cell::Cell(double initialValue) :mValue(initialValue)
{
}
