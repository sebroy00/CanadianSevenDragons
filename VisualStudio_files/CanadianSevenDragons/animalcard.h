#ifndef ANIMALCARD_H
#define ANIMALCARD_H
#include<iostream>
#include<string>
using namespace std;

enum Orientation {UP, DOWN};
enum EvenOdd {EVEN, ODD};

/*Classe Virtuelle*/
class AnimalCard {

	//variable d'instances 

protected: //a determiner
	/*change l’orientation de la carte*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow(EvenOdd);
};

#endif // !ANIMALCARD_H

