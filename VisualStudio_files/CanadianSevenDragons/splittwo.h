/*
splittwo.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/


#include"animalcard.h"
#include <stdio.h>     
#include <cstdlib>
#include <ctime>

#ifndef SPLITTWO_H
#define SPLITTWO_H

using namespace std;

class SplitTwo : public AnimalCard {

public:
	/*Constructeur 2 paramametre*/
	SplitTwo(char, char);

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

#endif // !SPLITTWO_H

