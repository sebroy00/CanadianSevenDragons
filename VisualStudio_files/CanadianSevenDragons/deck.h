#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

#include"exeptions.h"

#ifndef DECK_H
#define DECK_H

using namespace std;

template<class T>
class Deck : public vector<T>{

public:
	//try to get the element on top
	T draw(){
		//faire un shared pointer vide
		if (size()>0) {
			return at(size()-1);
		}
		else{
			throw MissingCard("Dans la methode draw et le deck est vide");
		}
	}
};
#endif //!DECK_H