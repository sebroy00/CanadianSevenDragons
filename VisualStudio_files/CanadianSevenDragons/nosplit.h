/*
nosplit.h
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#ifndef NOSPLIT_H
#define NOSPLIT_H

#include"animalcard.h"

using namespace std;

class NoSplit : public AnimalCard {

public:
	NoSplit(){};
	/*Constructeur 1 paramametre*/
	NoSplit(char animal) {
		for (int i = 0; i < 4; i++)
			d_animals[i] = animal;
	};

	/*orientation reste toujours pareille*/
	virtual void setOrientation(Orientation);

	/*est utilis� par printRow lors de l�affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caract�res correspondant de la carte.*/
	virtual void printRow();

	virtual bool findAnimal(char);

	virtual char getAnimalAt(int);
};


class Joker :public NoSplit {

public:
	Joker() :  NoSplit('j') {};
};

class StartCard :public NoSplit {

public:
	StartCard() : NoSplit('c') {};
};

#endif // !NOSPLIT_H