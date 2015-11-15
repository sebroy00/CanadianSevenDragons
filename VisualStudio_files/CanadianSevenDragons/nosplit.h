#ifndef NOSPLIT_H
#define NOSPLIT_H
#include"animalcard.h"
using namespace std;

class NoSplit : AnimalCard{

	//variable d'instances 

public: 
	/*Constructeur 1 paramametre*/
	NoSplit(string) {}; 

	/*orientation reste toujours pareille*/
	virtual void setOrientation(Orientation);

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd);

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow(EvenOdd);
};

#endif // !NOSPLIT_H

class Joker:public NoSplit{

};

class StartCard :public NoSplit{

};
