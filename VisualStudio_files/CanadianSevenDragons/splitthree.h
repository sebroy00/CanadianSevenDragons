#ifndef SPLITTHREE_H
#define SPLITTHREE_H
#include"animalcard.h"
#include <stdio.h>     
#include <cstdlib>
#include <ctime>
using namespace std;

class SplitThree : AnimalCard {

	Orientation d_orientation = Orientation::UP;
	EvenOdd d_evenOdd = EvenOdd::EVEN;
	string d_animals[4];

public:
	/*Constructeur 3 paramametre*/
	SplitThree(string, string, string);

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

#endif // !SPLITTHREE_H

