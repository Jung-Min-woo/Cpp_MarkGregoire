#pragma once
#include <cstddef>
#include "SpreadsheetCell.h"

class SpreadsheetApplication; //Forward Declaration

class Spreadsheet {
public:
	Spreadsheet(size_t width, size_t height, SpreadsheetApplication& App);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; //moving syntax
	Spreadsheet& operator=(Spreadsheet && rhs) noexcept; //moving syntax
	Spreadsheet& operator=(const Spreadsheet& rhs);
	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
	~Spreadsheet();
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	const SpreadsheetCell& getCellAt(size_t x, size_t y) const;
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	size_t getId() const;
	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

	class Cell {
	public:
		Cell() = default;
		Cell(double initialValue);
	private:
		double mValue;
	};

private:
	static size_t sCounter = 0;
	size_t mId = 0;
	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;
	void verifyCoordinate(size_t x, size_t y) const;
	bool inRange(size_t value, size_t upper) const;
	Spreadsheet() = default;

	static size_t inline sCounter = 0; //need to get inline
	size_t mId = 0;
	SpreadsheetApplication& mTheApp;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;
};