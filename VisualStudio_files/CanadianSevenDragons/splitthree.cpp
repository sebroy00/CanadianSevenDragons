/*
splitthree.cpp
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include "splitthree.h"

SplitThree::SplitThree(char animal1, char animal2, char animal3) {
	int random0to3 = rand() % 4;

	if (random0to3 == 0) {
		d_animals[0] = animal1;
		d_animals[1] = animal1;
		d_animals[2] = animal2;
		d_animals[3] = animal3;
	}
	else if (random0to3 == 1) {
		d_animals[1] = animal1;
		d_animals[3] = animal1;
		d_animals[0] = animal2;
		d_animals[2] = animal3;
	}
	else if (random0to3 == 2) {
		d_animals[2] = animal1;
		d_animals[3] = animal1;
		d_animals[0] = animal2;
		d_animals[1] = animal3;
	}
	else if (random0to3 == 3) {
		d_animals[0] = animal1;
		d_animals[2] = animal1;
		d_animals[1] = animal2;
		d_animals[3] = animal3;
	}
}
void SplitThree::setOrientation(Orientation _orientation) {
	d_orientation = _orientation;
}

void SplitThree::setRow(EvenOdd _evenodd) {
	d_evenOdd = _evenodd == EVEN ? ODD : EVEN;
}

void SplitThree::printRow() {
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

bool SplitThree::findAnimal(char _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

char SplitThree::getAnimalAt(int a) {
	if (d_orientation == UP)
		return d_animals[a];
	else if (d_orientation == DOWN) {
		return d_animals[abs(a - 3)];
	}
}
