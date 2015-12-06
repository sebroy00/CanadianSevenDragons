#include "table.h"
#include"exeptions.h"

int match(shared_ptr<AnimalCard> around, shared_ptr<AnimalCard> card, int around_coord, int card_coord) {
	return around->getAnimalAt(around_coord) == card->getAnimalAt(card_coord) /*match of two animals in both cards*/
			|| around->getAnimalAt(around_coord) == 'c' /*card around is startCard with c*/
			|| card->getAnimalAt(card_coord) == 'j' /*card placed is a joker*/
			? 1 : 0; 
}

int isConnected(std::shared_ptr<AnimalCard> around[4], std::shared_ptr<AnimalCard> card){
	int paired[4] = { 0,0,0,0 };
	/*Left*/
	if (around[0] != 0) {
		paired[0] |= match(around[0], card, 1, 0); 
		paired[2] |= match(around[0], card, 3, 2); 
	}
		if (card->getAnimalAt(0) == card->getAnimalAt(2)) {
			paired[0] |= paired[2];
			paired[2] = 0; //on garde le compte pour seulement une carte s'il y a une paire
		}
	/*Top*/
	if (around[1] != 0) {
		paired[0] |= match(around[1], card, 2, 0); 
		paired[1] |= match(around[1], card, 3, 1); 
	}
		if (card->getAnimalAt(0) == card->getAnimalAt(1)) {
			paired[1] |= paired[0];
			paired[0] = 0; 
		}
	/*Right*/
	if (around[2] != 0) {
		paired[1] |= match(around[2], card, 0, 1); 
		paired[3] |= match(around[2], card, 2, 3); 
	}
		if (card->getAnimalAt(1) == card->getAnimalAt(3)) {
			paired[3] |= paired[1];
			paired[1] = 0; 
		}
	/*Bottom*/
	if (around[3] != 0) {
		paired[3] |= match(around[3], card, 1, 3); 
		paired[2] |= match(around[3], card, 0, 2); 
	}
		if (card->getAnimalAt(3) == card->getAnimalAt(2)) {
			paired[2] |= paired[3];
			paired[3] = 0; 
		}

	return paired[0] + paired[1] + paired[2] + paired[3];
}

int Table::addAt(std::shared_ptr<AnimalCard> card, int row, int col) {
	/*Utiliser exception illegal placement*/
	if (row < 0 || col < 0 || row > NUM_L || col > NUM_C) {
		/*?Throw exception?*/
		return 0;
	}
	if (table[row][col] != 0) {
		throw IllegalPlacement("coordonnee existe pas");
	}

	/*LEFT, TOP, RIGHT, BOTTOM*/
	shared_ptr<AnimalCard> around[4];
	around[0] = col - 1 < 0 || row < 0 ? 0 : table[row][col - 1]; //left
	around[1] = row - 1 < 0 || col < 0 ? 0 : table[row - 1][col]; //top
	around[2] = col + 1 > NUM_C ? 0 : table[row][col + 1]; //right
	around[3] = row + 1 > NUM_L ? 0 : table[row + 1][col]; //bottom

	int numConnections = isConnected(around, card);

	if (numConnections == 0) {
		throw IllegalPlacement("aucune connection");
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

bool Table::win(char & animal) {
	int count(0);
	for (int l = 0; l < NUM_L; l++)
		for (int c = 0; c < NUM_C; c++) {
			if (table[l][c] != 0)
				if (table[l][c]->findAnimal(animal) || table[l][c]->findAnimal('j')) //a modifier en fonction de la classe Animal
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
