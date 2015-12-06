#include <iostream>
#include "AnimalCardFactory.h"

AnimalCardFactory::AnimalCardFactory(){

	
	//il y a 3 animaux par carte, donc un total de 60 animaux doivent etre genere
	//ensuite faire sur que toute les triples soient differents pour generer 20 cartes uniques
	//repeter pour split two et split 4
	vector<char> a(60);
	for (int i = 0; i < 12; i++)
	{
		a[i*5+0] = 'b';
		a[i*5+1] = 'w';
		a[i*5+2] = 'm';
		a[i*5+3] = 'h';
		a[i*5+4] = 'd';
	}
	random_shuffle(a.begin(), a.end());

	vector<string> tripples;
	bool differentes = false;
	string pair;

	while (!differentes){
		for (int i = 0; i < 20; i++)
		{
			pair += a[i * 3];
			pair += a[i * 3 + 1];
			pair += a[i * 3 + 2];
			tripples.push_back(pair);
			pair = "";
		}
		//voir si il y a duplication
		std::sort(tripples.begin(), tripples.end());
		auto il = std::adjacent_find(tripples.begin(), tripples.end());
		if (il == tripples.end()){ differentes = true; }
		else{tripples.clear(); random_shuffle(a.begin(), a.end());}
	}

	//faire les 20 triples
	for (int i = 0; i < 20; i++)
	{
		deck.push_back(shared_ptr<SplitThree>(new SplitThree(a[i * 3 + 0], a[i * 3 + 1], a[i * 3 + 2])));
	}
	
	//faire un autre shuffle des 60 animaux
	random_shuffle(a.begin(), a.end());
	
	//Faire des quad de string et comparer pour faire sur que toute les cartes seront differentes
	vector<string> quad;
	differentes = false;
	
	while (!differentes){
		for (int i = 0; i < 15; i++)
		{
			pair += a[i * 4];
			pair += a[i * 4 + 1];
			pair += a[i * 4 + 2];
			pair += a[i * 4 + 3];
			quad.push_back(pair);
			pair = "";
		}
		//voir si il y a duplication
		std::sort(quad.begin(), quad.end());
		auto il = std::adjacent_find(quad.begin(), quad.end());
		if (il == quad.end()){ differentes = true; }
		else{ quad.clear(); random_shuffle(a.begin(), a.end()); }
	}

	//15 cartes split 4
	for (int i = 0; i < 15; i++)
	{
		deck.push_back(shared_ptr<SplitFour>(new SplitFour(a[i * 4 + 0], a[i * 4 + 1], a[i * 4 + 2], a[i * 4 + 3])));
	}

	//recree avec 20 animaux et faire un shuffle
	vector<char> smallerAnimalSet(20);
	for (int i = 0; i < 4; i++)
	{
		smallerAnimalSet[i * 5 + 0] = 'b';
		smallerAnimalSet[i * 5 + 1] = 'w';
		smallerAnimalSet[i * 5 + 2] = 'm';
		smallerAnimalSet[i * 5 + 3] = 'h';
		smallerAnimalSet[i * 5 + 4] = 'd';
	}

	random_shuffle(smallerAnimalSet.begin(), smallerAnimalSet.end());

	//Faire des paires pour faire sur que toute les carates seront differentes
	vector<string> pairs;
	differentes = false;
	while (!differentes){
		for (int i = 0; i < 10; i++)
		{
			pair += smallerAnimalSet[i * 2];
			pair += smallerAnimalSet[i * 2 + 1];
			pairs.push_back(pair);
			pair = "";
		}
		//voir si il y a duplication
		std::sort(pairs.begin(), pairs.end());
		auto il = std::adjacent_find(pairs.begin(), pairs.end());
		if (il == pairs.end()){ differentes = true; }
		else{ pairs.clear(); random_shuffle(smallerAnimalSet.begin(), smallerAnimalSet.end()); }
	}
	
	for (int i = 0; i < 10; i++)
	{
		deck.push_back(shared_ptr<SplitTwo>(new SplitTwo(smallerAnimalSet[i * 2 + 0], smallerAnimalSet[i * 2 + 1])));
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


