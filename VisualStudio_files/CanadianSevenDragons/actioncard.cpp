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

	while (!qr.getX && qr.getY){
		cout << "SVP rentrer les coordonnes de la carte a enlever de la table" << endl;
		//rentrer x
		cout << "x:";
		cin >> qr.getX;
		cout << endl;
		//rentrer y
		cout << "y:";
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
	
	//enlever la carte du tableau et la remplacer pas un object null
	//Enlever les points pour les collections
	_table.pickAt(_query.getX, _query.getY);
	
	//faire sur que la carte a ete enleve
	cout << typeid(_table.pickAt(_query.getX, _query.getY)).name() << endl;

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
			cout << "Votre joueur n a as pu etre trouve, vous pouvez selecctionner le joueur:" << endl;
			for (int i = 0; i < qr.nombreDeJoueurs; i++){
				cout << i << ". " << _player[i].getName() << endl;
			}
			cout << "Numero du joueur: ";
			cin >> a;
			if (0<a<qr.nombreDeJoueurs && a!=de){
				trouveJoueur = true;
				qr.action = _player[a].getName();
			}
		}
	} while (trouveJoueur);

	swap(_player[de].hand, _player[a].hand);
}

/*
Simplement aller chercher la carte action qu'il faut changer
*/
QueryResult HareAction::query(){
	cout << "Vous avez la carte Hare Action. Avec quel joueur souhaiteriez vous changer votre carte objectif" << endl;

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


void HareAction::perform(Table & _table, Player * _player, QueryResult qr){

	int de, a;
	bool trouveJoueur = false;
	QueryResult qr;
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
			cout << "Votre joueur n a as pu etre trouve, vous pouvez selecctionner le joueur:" << endl;
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
	} while (trouveJoueur);

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
QueryResult DeerAction::query(){
	cout << "Vous avez la carte Deer Action" << endl;

	QueryResult qr;
	return qr;
}

/*
tourner les cartes secretes et les cartes objectifs passent au joueur plus haut
*/
void DeerAction::perform(Table & _table, Player * _player, QueryResult qr){
	

	//garder la carte objectif du premier joueur
	for (int a = 0; a < qr.nombreDeJoueurs; a++){
		
	}

}

QueryResult MooseAction::query(){
	cout << "Vous avez la carte MooseAction. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;

	QueryResult qr;
	return qr;
}
void MooseAction::perform(Table & _table, Player * _player, QueryResult qr){

}




