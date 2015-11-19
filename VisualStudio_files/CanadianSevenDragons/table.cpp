#include "table.h"

int isConnected(std::shared_ptr<AnimalCard> around[4], std::shared_ptr<AnimalCard> card, int row, int col){
	int paired[4] = { 0,0,0,0 };

	/*Left*/
	if (around[0] != 0) {
		paired[0] |= around[0]->getAnimalAt(1) == card->getAnimalAt(0);
		paired[2] |= around[0]->getAnimalAt(3) == card->getAnimalAt(2) ? 1 : 0;
		if (card->getAnimalAt(0) == card->getAnimalAt(2)) {
			paired[0] |= paired[2];
			paired[2] = 0; //on garde le compte pour seulement une carte
		}
	}
	/*Top*/
	if (around[1] != 0) {
		paired[0] |= paired[0] || around[1]->getAnimalAt(2) == card->getAnimalAt(0) ? 1 : 0;
		paired[1] |= paired[1] || around[1]->getAnimalAt(3) == card->getAnimalAt(1) ? 1 : 0;
		if (card->getAnimalAt(0) == card->getAnimalAt(1)) {
			paired[1] |= paired[0];
			paired[0] = 0; //on garde le compte pour seulement une carte
		}
	}
	/*Right*/
	if (around[2] != 0) {
		paired[1] |= around[2]->getAnimalAt(0) == card->getAnimalAt(1) ? 1 : 0;
		paired[3] |= around[2]->getAnimalAt(2) == card->getAnimalAt(3) ? 1 : 0;
		if (card->getAnimalAt(1) == card->getAnimalAt(3)) {
			paired[3] |= paired[1];
			paired[1] = 0; //on garde le compte pour seulement une carte
		}
	}
	/*Bottom*/
	if (around[3] != 0) {
		paired[3] |= around[3]->getAnimalAt(1) == card->getAnimalAt(3) ? 1 : 0;
		paired[2] |= around[3]->getAnimalAt(0) == card->getAnimalAt(2) ? 1 : 0;
		if (card->getAnimalAt(3) == card->getAnimalAt(2)) {
			paired[2] |= paired[3];
			paired[3] = 0; //on garde le compte pour seulement une carte
		}
	}

	return paired[0] + paired[1] + paired[2] + paired[3];
}

int verif() {

	return 0;
}

int Table::addAt(std::shared_ptr<AnimalCard> card, int row, int col) {
	/*Utiliser exception illegal placement*/

	/*LEFT, TOP, RIGHT, BOTTOM*/
	shared_ptr<AnimalCard> around[4];
	around[0] = table[row][col - 1]; //left
	around[1] = table[row - 1][col]; //top
	around[2] = table[row][col + 1]; //right
	around[3] = table[row + 1][col]; //bottom

	int numConnections = isConnected(around, card, row, col);

	if (numConnections == 0) {
		/*?Throw exception?*/
		return 0;
	}
	table[row][col] = card;
	return numConnections;
}

std::shared_ptr<AnimalCard> Table::pickAt(int row, int col) {
	shared_ptr<AnimalCard> tmp = table[row][col];
	table[row][col] = shared_ptr<AnimalCard>();
	return tmp;
}

std::shared_ptr<AnimalCard> Table::get(int row, int col) {
	return table[row][col];
}

bool Table::win(std::string & animal) {
	int count(0);
	for (int l = 0; l < NUM_L; l++)
		for (int c = 0; c < NUM_C; c++) {
			if (table[l][c] != 0)
				if (table[l][c]->findAnimal(animal)) //a modifier en fonction de la classe Animal
					count++;
		}
	return (count >= WIN);
}


void Table::printTable() {
	int startRow(52), startCol(52), endRow(52), endCol(52);

	/*On sait qu'il y a deja une carte au centre
	  On trouve la premiere ligne et la premiere
	  colonne ou une carte apparait (peut etre different)
	  ainsi que la derniere ligne et colonne*/
	for (int l = 0; l < 103; l++) {
		for (int c = 0; c < 103; c++) {
			if (table[l][c] != 0) {
				if (l < startRow)
					startRow = l;
				if (c < startCol)
					startCol = c;
				if (l > endRow)
					endRow = l;
				if (c > endCol)
					endCol = c;
			}
		}
	}
	bool printedRow = true;
	bool coordColPrint = true;

	for (int l = startRow; l <= endRow; l++) {
		if (!coordColPrint) {
			string colCoord(to_string(l).size() == 2 ? to_string(l) : " " + to_string(l));
			cout << colCoord << "|";
		}
		else
			cout << "   ";
		for (int c1 = startCol; c1 <= endCol; c1++) {
			if (coordColPrint) {
				cout << c1 << " ";
			}
			else if (table[l][c1] != 0) {
				table[l][c1]->printRow();
			}
			else
				cout << "   "; //trois espaces
		}
		cout << endl;
		if (!coordColPrint)
			cout << "  |";
		else
			cout << "   ";

		for (int c2 = startCol; c2 <= endCol; c2++) {
			if (coordColPrint) {
				cout << "__" << " ";
			}
			else if (table[l][c2] != 0)
				table[l][c2]->printRow();
			else
				cout << "   "; //trois espaces
		}
		cout << endl;
		if (coordColPrint) {
			coordColPrint = false;
			l--;
		}
	}

}
