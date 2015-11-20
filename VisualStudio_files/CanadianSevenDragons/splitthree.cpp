#include "splitthree.h"

SplitThree::SplitThree(string animal1, string animal2, string animal3) {
	srand(time(0));
	int random0to1 = rand() % 3;

	if (random0to1 == 0) {
		d_animals[0] = animal1;
		d_animals[1] = animal1;
		d_animals[2] = animal2;
		d_animals[3] = animal3;
	}
	else if (random0to1 == 1) {
		d_animals[0] = animal2;
		d_animals[2] = animal1;
		d_animals[1] = animal1;
		d_animals[3] = animal3;
	}
	else if (random0to1 == 2) {
		d_animals[0] = animal2;
		d_animals[1] = animal3;
		d_animals[2] = animal1;
		d_animals[3] = animal1;
	}
	else if (random0to1 == 3) {
		d_animals[0] = animal1;
		d_animals[1] = animal2;
		d_animals[2] = animal3;
		d_animals[3] = animal1;
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

bool SplitThree::findAnimal(string _animal)
{
	for (int c = 0; c < 4; c++)
		if (d_animals[c] == _animal)
			return true;
	return false;
}

string SplitThree::getAnimalAt(int a) {
	if (d_orientation == UP)
		return d_animals[a];
	else if (d_orientation == DOWN) {
		return d_animals[abs(a - 3)];
	}
}
