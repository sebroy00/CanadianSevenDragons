/*
splitfour.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include "splitfour.h"

SplitFour::SplitFour(char animal1, char animal2, char animal3, char animal4) {
	d_animals[0] = animal1;
	d_animals[1] = animal2;
	d_animals[2] = animal3;
	d_animals[3] = animal4;
}
void SplitFour::setOrientation(Orientation _orientation) {
	d_orientation = _orientation;
}

void SplitFour::setRow(EvenOdd _evenodd) {
	d_evenOdd = _evenodd == EVEN ? ODD : EVEN;
}

void SplitFour::printRow() {
	if (d_orientation == UP && d_evenOdd == EVEN) {
		cout << d_animals[0] << d_animals[1] << " ";
	}
	else if (d_orientation == UP && d_evenOdd == ODD) {
		cout << d_animals[2] << d_animals[3] << " ";
	}
	else if (d_orientation == DOWN && d_evenOdd == EVEN) {
		cout << d_animals[3] << d_animals[2] << " ";
	}
	else if (d_orientation == DOWN && d_evenOdd == ODD) {
		cout << d_animals[1] << d_animals[0] << " ";
	}
	setRow(d_evenOdd);
}

bool SplitFour::findAnimal(char _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

char SplitFour::getAnimalAt(int a) {
	if (d_orientation == UP)
		return d_animals[a];
	else if (d_orientation == DOWN) {
		return d_animals[abs(a - 3)];
	}
}
