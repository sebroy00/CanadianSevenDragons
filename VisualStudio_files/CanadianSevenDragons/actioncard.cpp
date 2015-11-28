#include <iostream>
#include "actioncard.h"

using namespace std;

//Faire l'implementation de toutes les actions

QueryResult BearAction::query(){

	cout << "Vous avez la carte Ours, voulez vous echanger votre main avec celle d'un autre joueur (y/n)" << endl;
	
	char reponse('_');
	while (reponse != 'y' || reponse !='n'){
		cin >> reponse;
		if (reponse == 'y'){
			cout << "Avec qui voulez-vous echanger votre carte " << endl;
			for (int i = 0; i < ; i++)
			{

			}
		}
	}

}
