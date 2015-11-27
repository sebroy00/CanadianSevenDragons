#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include"hand.h"
using namespace std;
class Player {
	char d_secretAnimal;
	string d_name;
public:
	Player(char);
	Hand hand;
	char swapSecretAnimal(char&);
	char getSecretAnimal();
	void printState();
	string getName();
	void setName(string);
};
#endif // !PLAYER_H

