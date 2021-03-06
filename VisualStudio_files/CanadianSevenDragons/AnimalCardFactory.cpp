/*
animalcardfactory.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include <iostream>
#include"animalcardfactory.h"

AnimalCardFactory::AnimalCardFactory() {
	/*shuffle device*/
	std::random_device rd;
	std::mt19937 mt(rd());

	/*pour rand()*/
	srand(time(0));

	vector<char> char_animals = { 'b','d','h','m','w' };

	/*5 noSplit*/
	for (int c = 0; c < 5; c++) {
		deck.push_back(shared_ptr<NoSplit>(new NoSplit(char_animals[c])));
	}

	/*10 SplitTwo*/
	for (int c = 0; c < 5; c++) {
		shuffle(char_animals.begin(), char_animals.end(), mt);
		deck.push_back(shared_ptr<SplitTwo>(new SplitTwo(char_animals[0], char_animals[1])));
		deck.push_back(shared_ptr<SplitTwo>(new SplitTwo(char_animals[2], char_animals[3])));
	}

	/*20 SplitTwo*/
	for (int c = 0; c < 5; c++) {
		shuffle(char_animals.begin(), char_animals.end(), mt);
		/*pour avoir un nombre equivalent d'animaux qui prennent deux cases, on cree 4 cartes avec le meme shuffle*/
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(char_animals[0], char_animals[1], char_animals[2])));
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(char_animals[1], char_animals[2], char_animals[3])));
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(char_animals[2], char_animals[3], char_animals[0])));
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(char_animals[3], char_animals[0], char_animals[1])));
	}

	/*15 SplitFour*/
	for (int c = 0; c < 15; c++) {
		shuffle(char_animals.begin(), char_animals.end(), mt);
		deck.push_back(shared_ptr<SplitFour>(new SplitFour(char_animals[0], char_animals[1], char_animals[2], char_animals[3])));
	}

	for (int i = 0; i < 3; i++)
	{
		deck.push_back(shared_ptr<BearAction>(new BearAction()));
		deck.push_back(shared_ptr<DeerAction>(new DeerAction()));
		deck.push_back(shared_ptr<MooseAction>(new MooseAction()));
		deck.push_back(shared_ptr<WolfAction>(new WolfAction()));
		deck.push_back(shared_ptr<HareAction>(new HareAction()));
	}


	deck.push_back(shared_ptr<Joker>(new Joker()));

	shuffle(deck.begin(), deck.end(), mt);
}

AnimalCardFactory * AnimalCardFactory::getFactory() {
	AnimalCardFactory * acf_ptr = new AnimalCardFactory();
	return acf_ptr;
}

//fonction simplement pour aller chercher le Deck
Deck<AnimalCard> AnimalCardFactory::getDeck() {
	if (deck.size() > 0) {
		return deck;
	}
	else {
		throw MissingCard("Le deck est vide");
	}

}


