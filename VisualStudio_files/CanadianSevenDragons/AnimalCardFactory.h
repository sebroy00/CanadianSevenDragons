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
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>

enum Animal{loup, ours, orignal, lievre, cerf};

class AnimalCardFactory{

	//5 ActionCard, 10 SplitTwo, 20 SplitThree and 15 SplitFour
	vector<ActionCard> actionCards;
	vector<AnimalCard> animalCards;
	Deck<std::shared_ptr<AnimalCard>> deck;

public:
	
	//Constructeur
	AnimalCardFactory();

	static AnimalCardFactory* getFactory();
	
	/*Representation de AnimalCard avec sharec pointers. Le Deck devrait etre un template class*/
	Deck <std::shared_ptr<AnimalCard>> getDeck();

};