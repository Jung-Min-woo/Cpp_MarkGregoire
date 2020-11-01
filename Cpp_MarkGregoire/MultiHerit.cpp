#include <iostream>
using namespace std;
class Dog {
public:
	virtual void bark() { cout << "Woof" << endl; }
	virtual void eat() { cout << "The dog ate" << endl; }
};
class Bird {
public:
	virtual void chirp() { cout << "Chirp" << endl; }
	virtual void eat() { cout << "The Bird ate" << endl; }
};
class DogBird : public Dog, public Bird {
};
int main(void) {
	DogBird myConfusedAnimal;
	//ERROR : AMBIGUOUS myConfusedAnimal.eat();
	//ERROR SOLVED
	dynamic_cast<Dog&>(myConfusedAnimal).eat();
	myConfusedAnimal.Dog::eat();
}