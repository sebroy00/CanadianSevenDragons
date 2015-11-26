#ifndef ANIMALCARD_H
#define ANIMALCARD_H
#include<iostream>
#include<string>
using namespace std;

enum Orientation { UP, DOWN };
/*EVEN = top , ODD = bottom */
enum EvenOdd { EVEN, ODD }; 

/*Classe Virtuelle*/
class AnimalCard {

protected:
	Orientation d_orientation = Orientation::UP;
	EvenOdd d_evenOdd = EvenOdd::EVEN;
	char d_animals[4];
public: //a determiner
	/*change l’orientation de la carte*/
	virtual void setOrientation(Orientation) = 0;

	/*est utilisé par printRow lors de l’affichage de la carte*/
	virtual void setRow(EvenOdd) = 0;

	/*affiche les deux caractères correspondant de la carte.*/
	virtual void printRow() = 0;

	virtual bool findAnimal(char) = 0;

	virtual char getAnimalAt(int) = 0;
};

#endif // !ANIMALCARD_H


