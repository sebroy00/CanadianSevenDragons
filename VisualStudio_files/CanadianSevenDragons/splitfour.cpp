#include "splitfour.h"

SplitFour::SplitFour(string animal1, string animal2, string animal3, string animal4) {
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

bool SplitFour::findAnimal(string _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

string SplitFour::getAnimalAt(int a) {
		return d_animals[a];
}
