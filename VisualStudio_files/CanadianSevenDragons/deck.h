/*
deck.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

#include"exeptions.h"

#ifndef DECK_H
#define DECK_H

using namespace std;

template<typename T>
class Deck : public vector<shared_ptr<T>>{

public:
	//try to get the element on top
	shared_ptr<T> draw(){
		//faire un shared pointer vide
		if (size()>0) {
			shared_ptr<T> tmp(back());
			pop_back();
			return tmp;
		}
		else{
			throw MissingCard("Dans la methode draw et le deck est vide");
		}
	}
};
#endif //!DECK_H