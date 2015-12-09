#include <iostream>

#in

using namespace std;


void TEST_actions(Table &_table, Player *p){

	//Ajouter quelques cartes au tableau
	shared_ptr<AnimalCard> ac = shared_ptr<AnimalCard>(new SplitFour('b', 'd', 'h', 'm'));

	_table.addAt(ac, 51, 52);
	_table.printTable();

	_table.addAt(ac, 53, 52);

	shared_ptr<AnimalCard> animalTwo = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalThree = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFour = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFive = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));

	cout << "Adding" << endl;
	_table.addAt(animalTwo, 52, 51);
	cout << "Adding" << endl;
	_table.addAt(animalThree, 52, 50);
	_table.addAt(animalFour, 52, 49);
	_table.addAt(animalFive, 52, 48);

	_table.printTable();

	//tester les fonctions actions avec les cartes
	QueryResult qr;
	qr.nombreDeJoueurs = 2;
	qr.nomDuJoueur = "seb";
	qr.action = "nic";

	BearAction * ba = new BearAction();

	cout << p[0].getName() << p[1].getName() << endl;

	cout << "Swap les mains" << endl;

	cout << "Main Seb" << endl;
	printHand((p[0]).hand);
	cout << "Main Nic" << endl;
	printHand((p[1]).hand);

	ba->perform(_table, &p[0], qr);

	cout << "Apres swap" << endl;
	cout << "Main Seb" << endl;
	printHand((p[0]).hand);
	cout << "Main Nic" << endl;
	printHand((p[1]).hand);

}