#include <iostream>
#include "animalcard.h"
#include "deck.h"
#include "nosplit.h"
#include "splitfour.h"
#include "splitthree.h"
#include "splittwo.h"
#include "actioncard.h"
#include <memory>
#include <list>

enum Animal{loup, ours, orignal, lievre, cerf};

class AnimalCardFactory{

	//5 ActionCard, 10 SplitTwo, 20 SplitThree and 15 SplitFour
	ActionCard *actionCards;
	SplitTwo *splitTwoCards;
	SplitThree *splitThreeCards;
	SplitFour *splitFourCards;

public:

	static AnimalCardFactory* getFactory();

	//Constructeur
	AnimalCardFactory();

	/*Representation de AnimalCard avec sharec pointers. Le Deck devrait etre un template class*/
	Deck <std::shared_ptr<AnimalCard>> getDeck();

};