
#ifndef DECK_H
#define DECK_H
#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <class T>

class Deck : public vector<T>{


public:
	shared_ptr<T> draw(){
		return this.pop_back();
	}
};
#endif //!DECK_H
