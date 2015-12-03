#include <iostream>
#include "actioncard.h"

using namespace std;

//Faire l'implementation de toutes les actions


QueryResult WolfAction::query(){

	cout << "Vous avez pige la carte loup!!!" << endl;
	cout << "Vous pouvez maintenant choisir une carte a retirer pour la mettre dans votre main" << endl;
	/*NE PAS ENLEVER CARTE AU CENTRE ET > 103 (< 0) ...*/
	QueryResult qr;
	//rentrer x
	cout << "x:";
	cin >> qr.getX;
	cout << endl;
	//rentrer y
	cout << "y:";
	cin >> qr.getY;
	cout << endl;

	return qr;
}

void WolfAction::perform(Table &_table, Player *_player, QueryResult _query){
	
}

QueryResult BearAction::query(){

	cout << "Vous avez la carte Bear Action. Avec quel joueur souhaiteriez vous changer votre main" << endl;
	
	//Imprimer les joueurs
	
	QueryResult qa;
	string nomDuJoueur;
	cin >> nomDuJoueur;
	cout << "Vous avex choisi de changer de main avec " << nomDuJoueur<<endl;
	qa.action = nomDuJoueur;
	return qa;

}

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

QueryResult HareAction::query(){
	cout << "Vous avez la carte Hare Action. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;

	QueryResult qr;
	return qr;
}

void HareAction::perform(Table & _table, Player * _player, QueryResult qr){

}

QueryResult DeerAction::query(){
	cout << "Vous avez la carte Deer Action. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;

	QueryResult qr;
	return qr;
}
void DeerAction::perform(Table & _table, Player * _player, QueryResult qr){
	
}

QueryResult MooseAction::query(){
	cout << "Vous avez la carte MooseAction. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;

	QueryResult qr;
	return qr;
}
void MooseAction::perform(Table & _table, Player * _player, QueryResult qr){

}




