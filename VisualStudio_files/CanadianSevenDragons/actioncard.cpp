#include <iostream>
#include "actioncard.h"

using namespace std;

//Faire l'implementation de toutes les actions


/*
Chercher les coordonnees de la carte a aller chercher 
*/

QueryResult WolfAction::query(){

	cout << "Vous pouvez maintenant choisir une carte a retirer pour la mettre dans votre main" << endl;
	/*NE PAS ENLEVER CARTE AU CENTRE ET > 103 (< 0) ...*/
	QueryResult qr;
	
	qr.getX = 0;
	qr.getY = 0;

	while (!qr.getX && !qr.getY){
		cout << "SVP rentrer les coordonnes de la carte a enlever de la table" << endl;
		//rentrer x
		cout << "Column :";
		cin >> qr.getX;
		cout << endl;
		//rentrer y
		cout << "Row :";
		cin >> qr.getY;
		cout << endl;
	}
	return qr;
}

/*
Retirer une carte du tableau. 
utiliser la fonction pick at
*/

void WolfAction::perform(Table &_table, Player *_player, QueryResult _query){
	
	int playerNum = 0;
	for (int i = 0; i < _query.nombreDeJoueurs; i++){
		if (_player[i].getName() == _query.nomDuJoueur){
			playerNum = i;
		}
	}
	//enlever la carte du tableau et la remplacer pas un object null
	//Enlever les points pour les collections
	_player[playerNum].hand += shared_ptr<AnimalCard>(_table.pickAt(_query.getY, _query.getX));
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

/*chercher la carte a changer sur le tableau, getX, getY, etX, setY, tester les bonnes coordonnee dans la main*/

QueryResult HareAction::query(){
	cout << "Vous avez la carte d'action lievre, veuillez donner l'emplacement de la carte que vous voulez changer " << endl;
	
	QueryResult qr;
	cout << "Start row:";
	cin >> qr.getX;
	cout << endl;
	cout << "Start column";
	cin >> qr.getY;
	cout << endl;
	cout << "End row";
	cin >> qr.endX;
	cout << endl;
	cout << "End column";
	cin >> qr.endY;
	return qr;
}

/*
Changer les cartes
Les emplacement devraient etre valides
*/

void HareAction::perform(Table & _table, Player * _player, QueryResult qr){

	shared_ptr<AnimalCard> tempStart = _table.pickAt(qr.getX, qr.getY);

	bool emplacementValide = false;
	int connections = 0;
	while (!emplacementValide)
	{
		connections = _table.addAt(tempStart, qr.endX, qr.endY);
		if (connections){
			emplacementValide = true;
		}
	}
	
}

/*
Simplement aller chercher la carte action qu'il faut changer
*/
QueryResult DeerAction::query(){
	cout << "Vous avez la carte Deer Action. Avec quel joueur souhaiteriez vous changer votre carte objectif" << endl;

	QueryResult qa;
	string nomDuJoueur;
	cin >> nomDuJoueur;
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
	cout << "Nom demande" << qr.nomDuJoueur << endl;
	cout << "Nom a " << qr.action << endl;
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
			cout << "Votre joueur n a as pu etre trouve, vous pouvez selectionner le joueur:" << endl;
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

	//faire un swap des cards objectifs
	//Gave on the left hand assignement of the getAniml function
	char tempAAnimal = _player[a].getSecretAnimal();
	char tempDeAnimal = _player[de].getSecretAnimal();
	_player[a].swapSecretAnimal(tempDeAnimal);
	_player[de].swapSecretAnimal(tempAAnimal);

	
}

/*
Pas besoins de query
*/
QueryResult MooseAction::query(){
	cout << "Vous avez la carte MooseAction. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;

	QueryResult qr;
	return qr;
}
/*
tourner les cartes secretes et les cartes objectifs passent au joueur plus haut
*/
void MooseAction::perform(Table & _table, Player * _player, QueryResult qr){

	//garder la carte objectif du premier joueur
	char dernierOCard = _player[qr.nombreDeJoueurs - 1].getSecretAnimal();

	//Montrer les cartes objectifs 
	cout << "Voici les cartes objectifs de tout les joueurs" << endl;
	for (int i = 0; i < qr.nombreDeJoueurs; i++)
	{
		cout << _player[i].getName() << " : " << _player[i].getSecretAnimal() << endl;
	}
	cout << "Les cartes seront pousse au prochain joueur, l'animal du dernier joueur va au premier joueur" << endl;
	for (int a = qr.nombreDeJoueurs-1; 0<a; a--){
		char tSC = _player[a-1].getSecretAnimal();
		_player[a].swapSecretAnimal(tSC);
	}
	_player[0].swapSecretAnimal(dernierOCard);

	//pour tester
	cout << "Voici les cartes objectifs de tout les joueurs" << endl;
	for (int i = 0; i < qr.nombreDeJoueurs; i++)
	{
		cout << _player[i].getName() << " : " << _player[i].getSecretAnimal() << endl;
	}


}




