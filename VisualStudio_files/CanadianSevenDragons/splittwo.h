#ifndef SPLITTWO_H
#define SPLITTWO_H
#include"animalcard.h"
using namespace std;

class SplitTwo : AnimalCard {

	Orientation d_orientation = Orientation::UP;
	EvenOdd d_evenOdd = EvenOdd::EVEN;
	string d_animals[4];

public:
	/*Constructeur 2 paramametre*/
	SplitTwo(string, string) {};

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow(EvenOdd);

	/*Va chercher l'animal a cette position*/
	virtual string getAnimalAt(int);
};

#endif // !SPLITTWO_H

