/*
splittwo.h
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

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
	SplitTwo(char, char);

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

#endif // !SPLITTWO_H

