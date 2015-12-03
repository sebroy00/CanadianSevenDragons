#include <iostream>
#include "animalcard.h"
#include "deck.h"
#include "splitfour.h"
#include "splitthree.h"
#include "splittwo.h"
#include "actioncard.h"
#include "exeptions.h"
#include <memory>
#include <list>
#include <algorithm>
#include <random>
#include <vector>

#ifndef ANIMALCARDFACTORY_D
#define ANIMALCARDFACTORY_D

enum Animal{loup, ours, orignal, lievre, cerf};

class AnimalCardFactory{

	//5 ActionCard, 10 SplitTwo, 20 SplitThree and 15 SplitFour
	Deck<AnimalCard> deck;

public:
	
	//Constructeur
	AnimalCardFactory();

	static AnimalCardFactory* getFactory();
	
	/*Representation de AnimalCard avec sharec pointers. Le Deck devrait etre un template class*/
	Deck <AnimalCard> getDeck();

};

#endif