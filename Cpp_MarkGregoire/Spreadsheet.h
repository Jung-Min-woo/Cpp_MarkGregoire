#pragma once
#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet {
public:
	size_t getID() const;
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; //moving syntax
	Spreadsheet& operator=(Spreadsheet && rhs) noexcept; //moving syntax
	Spreadsheet& operator=(const Spreadsheet& rhs);
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
	~Spreadsheet();
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const;
	SpreadsheetCell& getCellAt(size_t x, size_t y);
private:
	static size_t sCounter = 0;
	size_t mId = 0;
	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;
	void verifyCoordinate(size_t x, size_t y) const;
	bool inRange(size_t value, size_t upper) const;
	Spreadsheet() = default;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;
};
