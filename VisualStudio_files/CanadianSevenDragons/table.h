/*
table.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include <iostream>
#include <memory>
#include "animalcard.h"
#include "nosplit.h"


#ifndef TABLE
#define TABLE



using namespace std;

const int NUM_L(103), NUM_C = 103, MID = 52, WIN = 3 /*TEMPORARIRE WIN*/;
class Table {

	shared_ptr<AnimalCard> table[NUM_L][NUM_C];
	
public:
	/*Place la start card au centre*/
	Table() { table[MID][MID] = shared_ptr<StartCard>(new StartCard()); }

	/*ajoute un animalCard a la position specifiee. Retourne # d'animaux sur la carte (1-4). Exception IllegalPlacement si invalide*/
	/*! Important*/
	int addAt(std::shared_ptr<AnimalCard>, int row, int col);

	/*retire la carte a cette position. null si aucune carte*/
	std::shared_ptr<AnimalCard> pickAt(int row, int col);

	/*retourne la carte a cette position. null si aucune carte*/
	std::shared_ptr<AnimalCard> get(int row, int col);

	/*retourne true si cet animal est present sur 12 cartes se trouvant sur la table*/
	bool win(char & animal);

	void printTable();
};

#endif
