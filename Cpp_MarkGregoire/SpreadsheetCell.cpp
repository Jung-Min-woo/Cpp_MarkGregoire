#include "SpreadsheetCell.h"
using namespace std;
SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue){}
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
{
}
void SpreadsheetCell::setValue(double inValue)
{
	mValue = inValue;
}
double SpreadsheetCell::getValue(void) const
{
	return mValue;
}
void SpreadsheetCell::setString(std::string_view inString)
{
	mValue = stringToDouble(inString);
}

std::string SpreadsheetCell::getString(void) const
{
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
