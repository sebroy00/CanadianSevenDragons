#include "table.h"

int Table::addAt(std::shared_ptr<AnimalCard> card, int row, int col) {
	/*A completer*/
	/*Utiliser exception illegal placement*/
	table[row][col] = card;
	return 1;
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
	for (int l = startRow; l <= endRow; l++) {
		for (int c1 = startCol; c1 <= endCol; c1++) {
			if (table[l][c1] != 0) {
				table[l][c1]->printRow();
				/*cout << l << c1; //affiche la position*/
			}
			else
				cout << "   "; //trois espaces
		}
		cout << endl;
		for (int c2 = startCol; c2 <= endCol; c2++) {
			if (table[l][c2] != 0)
					table[l][c2]->printRow();
				/*cout << l << c2; //affiche la position*/
			else
				cout << "   "; //trois espaces
		}
		cout << endl;
	}

}
