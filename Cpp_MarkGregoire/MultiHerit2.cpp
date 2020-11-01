#include <iostream>
using namespace std;
class Animal {
public:
	virtual void eat() = 0;
};
class Dog : public Animal{
public:
	virtual void bark() { cout << "Woof" << endl; }
	virtual void eat() override { cout << "The Dog Ate" << endl; }
};
class Bird : public Animal {
public:
	virtual void chirp() { cout << "Chirp" << endl; }
	virtual void eat() override { cout << "The Bird Ate" << endl; }
};
class DogBird : public Dog, public Bird {
public:
	using Dog::eat; 
};
int main(void) {

}