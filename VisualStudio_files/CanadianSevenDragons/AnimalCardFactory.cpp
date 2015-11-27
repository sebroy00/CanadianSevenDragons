#include <iostream>
#include <vector>
#include "AnimalCardFactory.h"

AnimalCardFactory::AnimalCardFactory(){
	
	//Faire un iteration des elements
	vector<ActionCard> actionCards;
	actionCards[0] = BearAction();
	actionCards[1] = DeerAction();
	actionCards[2] = MooseAction();
	actionCards[3] = WolfAction();
	actionCards[4] = HareAction();

	
	// faire le shuffle avec la fonction shuffle 
	random_shuffle(actionCards.begin(), actionCards.end());
	
	//pour les 20 cartes, il faut trouver une representation egale de tout les animaux
	//il y a 3 animaux par carte, donc un total de 60 animaux doivent etre genere
	vector<string> a;
	for (int i = 0; i < 12; i++)
	{
		a[i*5+0] = "ours";
		a[i*5+1] = "loup";
		a[i*5+2] = "orignal";
		a[i*5+3] = "lievre";
		a[i*5+4] = "cerf";
	}

	//faire un shuffle des 60 animaux
	random_shuffle(a.begin(), a.end());
	
	//faire un array de 60 animaux
	for (int i = 0; i < 20; i++)
	{
		animalCards[i] = SplitThree(a[i * 3 + 0], a[i * 3 + 1], a[i * 3 + 2]);
	}
	
	//faire un autre shuffle des 60 animaux
	random_shuffle(a.begin(), a.end());
	
	//15 cartes
	for (int i = 0; i < 15; i++)
	{
		animalCards[i] = SplitFour(a[i * 4 + 0], a[i * 4 + 1], a[i * 4 + 2], a[i * 4 + 3]);
	}
	
	//recree avec 20 animaux et faire un shuffle
	vector<string> smallerAnimalSet;
	for (int i = 0; i < 4; i++)
	{
		smallerAnimalSet[i * 5 + 0] = "ours";
		smallerAnimalSet[i * 5 + 1] = "loup";
		smallerAnimalSet[i * 5 + 2] = "orignal";
		smallerAnimalSet[i * 5 + 3] = "lievre";
		smallerAnimalSet[i * 5 + 4] = "cerf";
	}
	
	random_shuffle(smallerAnimalSet.begin(), smallerAnimalSet.end());
	
	for (int i = 0; i < 10; i++)
	{
		animalCards[i] = SplitTwo(a[i * 2 + 0], a[i * 2 + 1]);
	}

	random_shuffle(animalCards.begin(), animalCards.end());
	random_shuffle(actionCards.begin(), actionCards.end());
}

