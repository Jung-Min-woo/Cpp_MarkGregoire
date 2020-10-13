#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;
class EvenSequence {
public:
	EvenSequence(std::initializer_list<double> args) {
		if (args.size() % 2 != 0) 
			throw std::invalid_argument("initializer_list shoud contain even number of elemenets");
		mSequence.assign(args);
		/*mSequence.reserve(args.size());
		for (const auto& value : args) {
			mSequence.push_back(value);
		}*/
	}
	void dump() const {
		for (const auto& value : mSequence)
			cout << value << ", ";
		cout << endl;
	}
private:
	std::vector<double> mSequence;
};
int main(void) {
	EvenSequence p1 = { 1.0, 2.0, 3., 4. , 5., 6. };
	p1.dump();
	try {
		EvenSequence p2 = { 1., 2., 3. };
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
}