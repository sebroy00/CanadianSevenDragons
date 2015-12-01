#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

#ifndef DECK_H
#define DECK_H

using namespace std;

template<class T>
class Deck : public vector<T>{

public:
	//try to get the element on top
	shared_ptr<T> draw(){
		//faire un shared pointer vide
		if (!this->back()) {
			return this->back();
		}
	}
};
#endif //!DECK_H