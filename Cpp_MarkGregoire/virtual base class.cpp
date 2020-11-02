#include <iostream>
using namespace std;
class Animal {
public:
	virtual void eat() = 0;
	virtual void sleep() {
		cout << "zzzzzzzzzzzzzzzzz......." << endl;
	}
};
class Dog : public virtual Animal {
public:
	virtual void bark() { cout << "Woof!" << endl; }
	virtual void eat() override { cout << "The Dog Ate" << endl; }
};
class Bird : public virtual Animal {
public:
	virtual void chirp() { cout << "Chirp" << endl; }
	virtual void eat() { cout << "The bird Ate" << endl; }
};
class DogBird : public Dog, public Bird{
public:
	virtual void eat() override { Dog::eat(); }
};
int main(void) {
	DogBird myConfusedAnimal;
	myConfusedAnimal.sleep();
	myConfusedAnimal.eat();
	return 0;
}