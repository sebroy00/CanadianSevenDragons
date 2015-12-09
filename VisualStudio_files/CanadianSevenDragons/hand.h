/*
hand.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <memory>
#include <list>
#include "animalcard.h"

class Hand {
	std::list<shared_ptr<AnimalCard> > d_animalcards = list<shared_ptr<AnimalCard> >();
public:
	/*Ajoute une carte dans la main du joueur*/
	Hand& operator+=(std::shared_ptr<AnimalCard>);

	/*retire une carte de la main du joueur, sinon exception MissingCard*/
	Hand& operator-=(std::shared_ptr<AnimalCard>);

	/*retourne la carte AnimalCard a cet index*/
	std::shared_ptr<AnimalCard>& operator[](int);

	/*retourne le nombre de cartes dans la main*/
	int noCards();

	/*affichage de la carte*/
	/*0  1  2  3
	  mw hw	ww BB
	  bb hm	hb BB */
	void printCard();

};

#endif // !HAND_H