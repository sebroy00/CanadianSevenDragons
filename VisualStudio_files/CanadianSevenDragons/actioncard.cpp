#include <iostream>
#include "actioncard.h"

using namespace std;

//Faire l'implementation de toutes les actions


QueryResult WolfAction::query(){

	cout << "Vous avez pige la carte loup!!!" << endl;
	cout << "Vous pouvez maintenant choisir une carte a retirer pour la mettre dans votre main" << endl;

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

	cout << "Vous avez la carte Bear Action. Vous pouvez maintenant. Avec quel joueur souhaiteriez vous changer votre main" << endl;
	
	//Imprimer les joueurs
	
	QueryResult qa;
	return qa;

}

void BearAction::perform(Table & _table, Player * _player, QueryResult qr){

}

QueryResult HareAction::query(){
	QueryResult qr;
	return qr;
}

void HareAction::perform(Table & _table, Player * _player, QueryResult qr){

}

QueryResult DeerAction::query(){
	QueryResult qr;
	return qr;
}
void DeerAction::perform(Table & _table, Player * _player, QueryResult qr){
	
}

QueryResult MooseAction::query(){
	QueryResult qr;
	return qr;
}
void MooseAction::perform(Table & _table, Player * _player, QueryResult qr){

}




