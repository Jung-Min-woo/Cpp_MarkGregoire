#pragma once
#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet {
public:
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet& operator=(const Spreadsheet& rhs);
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
	~Spreadsheet();
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
private:
	void verifyCoordinate(size_t x, size_t y) const;
	bool inRange(size_t value, size_t upper) const;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;
};
