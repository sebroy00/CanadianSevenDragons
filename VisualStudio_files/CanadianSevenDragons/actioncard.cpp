/*
actioncard.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include <iostream>
#include "actioncard.h"
#include "exeptions.h"

using namespace std;

//Faire l'implementation de toutes les actions


/*
Chercher les coordonnees de la carte a aller chercher 
*/

QueryResult WolfAction::query(){

	cout << "Vous pouvez maintenant choisir une carte a retirer pour la mettre dans votre main" << endl;

	QueryResult qr;
	qr.getX = 0;
	qr.getY = 0;

	while (!qr.getX && !qr.getY && !(qr.getX==52 && qr.getY==52)){
		cout << "SVP rentrer les coordonnes de la carte a enlever de la table" << endl;
		cout << "Vertical :   ";cin >> qr.getX;
		cout << "Horizontal : ";cin >> qr.getY;
	}
	return qr;
}

/*
Retirer une carte du tableau et la mettre dans la main du joueur selectionne
utiliser la fonction pick at
*/

void WolfAction::perform(Table &_table, Player *_player, QueryResult _query){
	if (_query.getX == 52 && _query.getY == 52)
		throw IllegalPlacement("On ne peut pas enlever la carte de depart");
	int playerNum = 0;
	for (int i = 0; i < _query.nombreDeJoueurs; i++){
		if (_player[i].getName() == _query.nomDuJoueur){
			playerNum = i;
		}
	}
	_player[playerNum].hand += _table.pickAt(_query.getX, _query.getY);
}

/*
trouver le joueur avec lequel il faut changer la main
*/
QueryResult BearAction::query(){

	cout << "Vous avez la carte Bear Action. Avec quel joueur souhaiteriez vous changer votre main" << endl;
	QueryResult qa;
	string nomDuJoueur;
	cin >> nomDuJoueur;
	cout << "Vous avex choisi de changer de main avec " << nomDuJoueur<<endl;
	qa.action = nomDuJoueur;
	return qa;
}
/*
Changer la main d'un joueur a un autre
*/
void BearAction::perform(Table & _table, Player * _player, QueryResult qr){

	//trouvver le joueur avec qui faire le changement
	int de, a;
	bool trouveJoueur = false;

	do{
		for (int i = 0; i < qr.nombreDeJoueurs; i++){
			if (_player[i].getName() == qr.nomDuJoueur){
				de = i;
			}
			if (_player[i].getName() == qr.action){
				a = i;
				trouveJoueur = true;
			}
		}
		if (!trouveJoueur){
			cout << "Votre joueur n a as pu etre trouve, vous pouvez selectionner le joueur: " << endl;
			for (int i = 0; i < qr.nombreDeJoueurs; i++){
				cout << i << ". " << _player[i].getName() << endl;
			}
			cout << "Numero du joueur: ";
			cin >> a;
			if (0 < a < qr.nombreDeJoueurs && a != de){
				trouveJoueur = true;
				qr.action = _player[a].getName();
			}
		}
	} while (!trouveJoueur);

	swap(_player[de].hand, _player[a].hand);
}

/*chercher la carte a changer sur le tableau, getX, getY, etX, setY, faire sur qu'on n'a pas la carte de depart */

QueryResult HareAction::query(){
	cout << "Vous avez la carte d'action lievre, veuillez donner l'emplacement de la carte que vous voulez changer " << endl;
	QueryResult qr;
	qr.getX = 0; qr.getY = 0;
	while (!qr.getX && !qr.getY && !(qr.getX == 52 && qr.getY == 52)){
		cout << "Emplacement vertical: ";cin >> qr.getX;
		cout << "Emplacement horizontal: ";cin >> qr.getY;
		cout << endl;
		cout << "Nouvel emplacement vertical: ";cin >> qr.endX;
		cout << "Nouvel emplacement horizontal: ";cin >> qr.endY;
	}
	return qr;
}

/*
Changer les cartes, les emplacements devraient etre valides
*/

void HareAction::perform(Table & _table, Player * _player, QueryResult qr){
	if (qr.getX == 52 && qr.getY == 52)
		throw IllegalPlacement("On ne peut pas enlever la carte de depart");
	shared_ptr<AnimalCard> tempStart = _table.pickAt(qr.getX, qr.getY);
	_table.addAt(tempStart, qr.endX, qr.endY);
}

/*
Simplement aller chercher la carte action qu'il faut changer
*/
QueryResult DeerAction::query(){
	cout << "Vous avez la carte Deer Action. Avec quel joueur souhaiteriez vous changer votre carte objectif" << endl;
	QueryResult qa;
	string nomDuJoueur; cin >> nomDuJoueur;
	cout << "Vous avex choisi de changer de main avec " << nomDuJoueur << endl;
	qa.action = nomDuJoueur;
	return qa;
}

/*
Changer la carte action d'un joueur a un autre
*/
void DeerAction::perform(Table & _table, Player * _player, QueryResult qr){
	int de, a;
	bool trouveJoueur = false;

	do{
		for (int i = 0; i < qr.nombreDeJoueurs; i++){
			if (_player[i].getName() == qr.nomDuJoueur){
				de = i;
			}
			if (_player[i].getName() == qr.action){
				a = i;
				trouveJoueur = true;
			}
		}

		if (!trouveJoueur){
			cout << "Votre joueur n a pas pu etre trouve, vous pouvez selectionner le joueur:" << endl;
			for (int i = 0; i < qr.nombreDeJoueurs; i++){
				cout << i << ". " << _player[i].getName() << endl;
			}
			cout << "Numero du joueur: ";
			cin >> a;
			if (0<a<qr.nombreDeJoueurs && a != de){
				trouveJoueur = true;
				qr.action = _player[a].getName();
			}
		}
	} while (!trouveJoueur);

	char tempAAnimal = _player[a].getSecretAnimal();
	char tempDeAnimal = _player[de].getSecretAnimal();
	_player[a].swapSecretAnimal(tempDeAnimal);
	_player[de].swapSecretAnimal(tempAAnimal);
}

/*
Pas besoins de query
*/
QueryResult MooseAction::query(){
	cout << "Vous avez la carte MooseAction " << endl;
	QueryResult qr;
	return qr;
}
/*
tourner les cartes secretes et les cartes objectifs passent au joueur plus haut
*/
void MooseAction::perform(Table & _table, Player * _player, QueryResult qr){

	//garder la carte objectif du premier joueur
	char dernierOCard = _player[qr.nombreDeJoueurs - 1].getSecretAnimal();
	for (int a = qr.nombreDeJoueurs-1; 0<a; a--){
		char tSC = _player[a-1].getSecretAnimal();
		_player[a].swapSecretAnimal(tSC);
	}
	_player[0].swapSecretAnimal(dernierOCard);
	cout << "Les carte secretes ont ete changes" << endl;
}




