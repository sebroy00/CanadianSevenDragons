#ifndef SPLITFOUR_H
#define SPLITFOUR_H
#include"animalcard.h"
using namespace std;

class SplitFour : public AnimalCard {
public:
	/*Constructeur 4 paramametre*/
	SplitFour(string, string, string, string);

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow();

	virtual bool findAnimal(string);

	/*Va chercher l'animal a cette position*/
	virtual string getAnimalAt(int);
};

#endif // !SPLITFOUR_H

