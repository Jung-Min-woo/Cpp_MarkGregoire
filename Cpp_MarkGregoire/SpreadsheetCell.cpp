#include "SpreadsheetCell.h"
using namespace std;
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue){}
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
{
}
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

double SpreadsheetCell::stringToDouble(std::string_view inString) const
{
	return strtod(inString.data(), nullptr);
}

std::string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue);
}
