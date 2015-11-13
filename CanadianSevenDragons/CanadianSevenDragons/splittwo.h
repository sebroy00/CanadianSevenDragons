#ifndef SPLITTWO_H
#define SPLITTWO_H
#include"animalcard.h"
using namespace std;

class SplitTwo : AnimalCard {

	//variable d'instances 

public:
	/*Constructeur 2 paramametre*/
	SplitTwo(string, string) {};

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow(EvenOdd);
};

#endif // !SPLITTWO_H

