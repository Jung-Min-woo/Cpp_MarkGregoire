#include "SpreadsheetCell.h"
#include <stdexcept>
using namespace std;
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue){}
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue)
{
}
void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}
double SpreadsheetCell::getValue(void) const
{
	mNumAccesses++;
	return mValue;
}
void SpreadsheetCell::set(std::string_view inString)
{
	mValue = stringToDouble(inString);
}

std::string SpreadsheetCell::getString(void) const
{
	mNumAccesses++;
	return doubleToString(mValue);
}

void SpreadsheetCell::setColor(Color color)
{
	mColor = color;
}

SpreadsheetCell::Color SpreadsheetCell::getColor() const
{
	return mColor;
}

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const
{
	return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

double SpreadsheetCell::stringToDouble(std::string_view inString) const
{
	return strtod(inString.data(), nullptr);
}

std::string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue);
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) 
		throw invalid_argument("Divide by zero.");
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return(lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return !(lhs < rhs);
}
