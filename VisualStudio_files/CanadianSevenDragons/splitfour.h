/*
splitfour.h
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include"animalcard.h"

#ifndef SPLITFOUR_H
#define SPLITFOUR_H

using namespace std;

class SplitFour : public AnimalCard {


public:
	/*Constructeur 4 paramametre*/
	SplitFour(char, char, char, char);

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow();

	virtual bool findAnimal(char);

	/*Va chercher l'animal a cette position*/
	virtual char getAnimalAt(int);
};

#endif // !SPLITFOUR_H

