#include <string>
#include <string_view>
class SpreadsheetCell {
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);
	void setValue(double inValue);
	double getValue(void) const;

	void setString(std::string_view inString);
	std::string getString(void) const;
private:
	double stringToDouble(std::string_view inString) const;
	std::string doubleToString(double inValue) const;

	double mValue;
};