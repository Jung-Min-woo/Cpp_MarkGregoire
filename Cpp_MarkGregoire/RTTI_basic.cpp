#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;
class Animal { 
public: virtual ~Animal() = default; 
};
class Dog : public Animal {};
class Bird : public Animal {};

void speak(const Animal& animal) {
	if (typeid(animal) == typeid(Dog))
		cout << "Woof!" << endl;
	else if (typeid(animal) == typeid(Bird))
		cout << "Chirp" << endl;
}

class Loggable{
public:
	virtual ~Loggable() = default;
	virtual std::string getLogMessage() const = 0;
};
class Foo : public Loggable {
public:
	std::string getLogMessage() const override;
};
std::string Foo::getLogMessage() const { return "Hello Logger"; };
void logObject(const Loggable& loggableobject) {
	cout << typeid(loggableobject).name() << ": ";
	cout << loggableobject.getLogMessage() << endl;
}
int main() {
	Foo log;
	logObject(log);
}