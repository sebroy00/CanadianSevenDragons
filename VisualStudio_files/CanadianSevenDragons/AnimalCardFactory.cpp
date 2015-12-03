#include <iostream>
#include "AnimalCardFactory.h"

AnimalCardFactory::AnimalCardFactory(){



	//pour les 20 cartes, il faut trouver une representation egale de tout les animaux
	//il y a 3 animaux par carte, donc un total de 60 animaux doivent etre genere
	vector<char> a(60);
	for (int i = 0; i < 12; i++)
	{
		a[i*5+0] = 'b';
		a[i*5+1] = 'w';
		a[i*5+2] = 'm';
		a[i*5+3] = 'h';
		a[i*5+4] = 'd';
	}

	//faire un shuffle des 60 animaux
	random_shuffle(a.begin(), a.end());
	
	//faire un array de 60 animaux
	for (int i = 0; i < 20; i++)
	{
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(a[i * 3 + 0], a[i * 3 + 1], a[i * 3 + 2])));
	}
	
	//faire un autre shuffle des 60 animaux
	random_shuffle(a.begin(), a.end());
	
	//15 cartes
	for (int i = 0; i < 15; i++)
	{
		deck.push_back(shared_ptr<SplitFour>(new SplitFour(a[i * 4 + 0], a[i * 4 + 1], a[i * 4 + 2], a[i * 4 + 3])));
	}
	
	//recree avec 20 animaux et faire un shuffle
	vector<string> smallerAnimalSet(20);
	for (int i = 0; i < 4; i++)
	{
		smallerAnimalSet[i * 5 + 0] = 'b';
		smallerAnimalSet[i * 5 + 1] = 'w';
		smallerAnimalSet[i * 5 + 2] = 'm';
		smallerAnimalSet[i * 5 + 3] = 'h';
		smallerAnimalSet[i * 5 + 4] = 'd';
	}
	
	random_shuffle(smallerAnimalSet.begin(), smallerAnimalSet.end());
	
	for (int i = 0; i < 10; i++)
	{
		deck.push_back(shared_ptr<SplitTwo>(new SplitTwo(a[i * 2 + 0], a[i * 2 + 1])));
	}

	deck.push_back(shared_ptr<BearAction>(new BearAction()));
	deck.push_back(shared_ptr<DeerAction>(new DeerAction()));
	deck.push_back(shared_ptr<MooseAction>(new MooseAction()));
	deck.push_back(shared_ptr<WolfAction>(new WolfAction()));
	deck.push_back(shared_ptr<HareAction>(new HareAction()));
	deck.push_back(shared_ptr<Joker>(new Joker()));
	
	cout << typeid(deck.back()).name() << endl;

	random_shuffle(deck.begin(), deck.end());
}

//fonction simplement pour aller chercher le Deck
Deck<AnimalCard> AnimalCardFactory::getDeck(){
	if (deck.size()>0){
		return deck;
	}
	else{
		throw MissingCard("Le deck est vide");
	}
	
}


