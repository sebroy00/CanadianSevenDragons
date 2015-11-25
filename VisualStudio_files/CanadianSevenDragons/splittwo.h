#ifndef SPLITTWO_H
#define SPLITTWO_H
#include"animalcard.h"
#include <stdio.h>     
#include <cstdlib>
#include <ctime>
using namespace std;

class SplitTwo : public AnimalCard {

public:
	/*Constructeur 2 paramametre*/
	SplitTwo(string, string);

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

#endif // !SPLITTWO_H

