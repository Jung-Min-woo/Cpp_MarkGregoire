#include <iostream>
#include <memory>
using namespace std;
class Cherry {
public: 
	virtual void printType(void) {}
};
class BigCherry :public Cherry {
public:
	virtual void polish(void) {}
};
class CherryTree {
public:
	virtual Cherry* pick(void);
};
class BigCherryTree : public CherryTree {
public:
	virtual BigCherry* pick(void) override;
};
Cherry* CherryTree::pick(){
	return new Cherry();
}
BigCherry* BigCherryTree::pick() {
	auto theCherry = std::make_unique<BigCherry>();
	theCherry->polish();
	return theCherry.release();
}
int main(void) {
	BigCherryTree theTree;
	std::unique_ptr<Cherry> theCherry(theTree.pick());
	theCherry->printType();
}