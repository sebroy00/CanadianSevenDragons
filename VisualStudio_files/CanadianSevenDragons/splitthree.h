#ifndef SPLITTHREE_H
#define SPLITTHREE_H
#include"animalcard.h"
using namespace std;

class SplitThree : AnimalCard {

	//variable d'instances 

public:
	/*Constructeur 3 paramametre*/
	SplitThree(string, string, string) {};

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow(EvenOdd);
};

#endif // !SPLITTHREE_H

