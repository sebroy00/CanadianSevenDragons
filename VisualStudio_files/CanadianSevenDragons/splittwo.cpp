#include "splittwo.h"

SplitTwo::SplitTwo(char animal1, char animal2) {
	srand(time(0));
	int random0to1 = rand() % 2;

	if (random0to1 == 0) {
		d_animals[0] = animal1;
		d_animals[1] = animal1;
		d_animals[2] = animal2;
		d_animals[3] = animal2;
	}
	else {
		d_animals[0] = animal1;
		d_animals[2] = animal1;
		d_animals[1] = animal2;
		d_animals[3] = animal2;
	}
}

void SplitTwo::setOrientation(Orientation _orientation) {
	d_orientation = _orientation;
}

void SplitTwo::setRow(EvenOdd _evenodd) {
	d_evenOdd = _evenodd == EVEN ? ODD : EVEN;
}

void SplitTwo::printRow() {
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

bool SplitTwo::findAnimal(char _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

char SplitTwo::getAnimalAt(int a) {
	if (d_orientation == UP)
		return d_animals[a];
	else if (d_orientation == DOWN) {
		return d_animals[abs(a - 3)];
	}
}
