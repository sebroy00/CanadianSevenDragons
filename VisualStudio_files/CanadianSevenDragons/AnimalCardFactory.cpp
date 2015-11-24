#include <iostream>
#include "AnimalCardFactory.h"

AnimalCardFactory::AnimalCardFactory(){
		
	//faire 5 cartes random
	int premierPic = rand() % 5;
	int deuxiemePic = rand() % 5;
	
	while (deuxiemePic != premierPic){
		deuxiemePic = rand() % 5;
	}
	
	//Faire un iteration des elements
	actionCards = new ActionCard[5];
	actionCards[0] = BearAction();
	actionCards[1] = DeerAction();
	actionCards[2] = MooseAction();
	actionCards[3] = WolfAction();
	actionCards[4] = HareAction();

	// faire le shuffle avec la fonction shuffle 
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(*actionCards, *(actionCards + 5), std::default_random_engine(seed));
		
	//pour les 20 cartes, il faut trouver une representation egale de tout les animaux
	//il y a 3 animaux par carte, donc un total de 60 animaux doivent etre genere
	string *a = new string[60];
	for (int i = 0; i < 12; i++)
	{
		a[i*5+0] = "ours";
		a[i*5+1] = "loup";
		a[i*5+2] = "orignal";
		a[i*5+3] = "lievre";
		a[i*5+4] = "cerf";
	}

	//faire un shuffle des 60 animaux
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(*a, *(a + 60), std::default_random_engine(seed));
	
	//faire un array de 60 animaux
	for (int i = 0; i < 20; i++)
	{
		animalCards[i] = SplitThree(a[i * 3 + 0], a[i * 3 + 1], a[i * 3 + 2]);
	}
	
	//reshuffle et remettre les elements
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(*a, *(a + 60), std::default_random_engine(seed));
	
	//15 cartes
	for (int i = 0; i < 15; i++)
	{
		animalCards[i] = SplitFour(a[i * 4 + 0], a[i * 4 + 1], a[i * 4 + 2], a[i * 4 + 3]);
	}
	
	//recree avec 20 animaux et faire un shuffle
	for (int i = 0; i < 4; i++)
	{
		a[i * 5 + 0] = "ours";
		a[i * 5 + 1] = "loup";
		a[i * 5 + 2] = "orignal";
		a[i * 5 + 3] = "lievre";
		a[i * 5 + 4] = "cerf";
	}
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(*a, *(a + 20), std::default_random_engine(seed));

	for (int i = 0; i < 10; i++)
	{
		splitTwoCards[i] = SplitTwo(a[i * 2 + 0], a[i * 2 + 1]);
	}

	//en faire

}