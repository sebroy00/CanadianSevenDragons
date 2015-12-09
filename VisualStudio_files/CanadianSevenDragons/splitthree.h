/*
splitthree.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include"animalcard.h"
#include <stdio.h>     
#include <cstdlib>
#include <ctime>

#ifndef SPLITTHREE_H
#define SPLITTHREE_H

using namespace std;

class SplitThree : public AnimalCard {


public:
	/*Constructeur 3 paramametre*/
	SplitThree(char, char, char);

	/*orientation change*/
	virtual void setOrientation(Orientation);

	/*est utilis� par printRow lors de l�affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caract�res correspondant de la carte.*/
	virtual void printRow();

	virtual bool findAnimal(char);

	/*Va chercher l'animal a cette position*/
	virtual char getAnimalAt(int);
};

#endif // !SPLITTHREE_H

