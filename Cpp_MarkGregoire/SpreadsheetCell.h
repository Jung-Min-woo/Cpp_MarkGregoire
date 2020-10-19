#include <string>
#include <string_view>
class SpreadsheetCell {
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);
	void set(double inValue);
	double getValue(void) const;

	void set(std::string_view inString);
	std::string getString(void) const;
private:
	double stringToDouble(std::string_view inString) const;
	std::string doubleToString(double inValue) const;
	double mValue;
	mutable size_t mNumAccesses = 0;
};