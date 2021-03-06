/*
nosplit.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include "nosplit.h"

void NoSplit::setOrientation(Orientation _orientation){
	d_orientation = _orientation;
}

void NoSplit::setRow(EvenOdd){
	d_evenOdd = EVEN ? ODD : EVEN;
}

void NoSplit::printRow(){
	if (d_orientation == UP && d_evenOdd == EVEN){
		cout << d_animals[0] << d_animals[1] << " ";
	}
	else if (d_orientation == UP && d_evenOdd == ODD) {
		cout << d_animals[2] << d_animals[3] << " ";
	}
	else if (d_orientation == DOWN && d_evenOdd == EVEN) {
		cout << d_animals[3] << d_animals[2] << " ";
	}
	else if (d_orientation == DOWN && d_evenOdd == ODD){ 
		cout << d_animals[1] << d_animals[0] << " ";
	}
	setRow(d_evenOdd);
}

bool NoSplit::findAnimal(char _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

char NoSplit::getAnimalAt(int a) {
	return d_animals[0]; //tous les animaux sont les memes, donc on peut retourne le premier element
}
