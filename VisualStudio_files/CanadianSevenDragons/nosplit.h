#ifndef NOSPLIT_H
#define NOSPLIT_H
#include"animalcard.h"
using namespace std;

class NoSplit : public AnimalCard {

	Orientation d_orientation = Orientation::UP;
	EvenOdd d_evenOdd = EvenOdd::EVEN;
	string d_animals[4];

public:
	NoSplit(){};
	/*Constructeur 1 paramametre*/
	NoSplit(string animal) {
		for (int i = 0; i < 4; i++)
			d_animals[i] = animal;
	};

	/*orientation reste toujours pareille*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow();

	virtual bool findAnimal(string);

	virtual string getAnimalAt(int);
};


class Joker :public NoSplit {

public:
	Joker() :  NoSplit("o") {};
};

class StartCard :public NoSplit {

public:
	StartCard() : NoSplit("c") {};
};

#endif // !NOSPLIT_H