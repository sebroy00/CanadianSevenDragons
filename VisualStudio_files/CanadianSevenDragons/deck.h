#ifndef DECK_H
#define DECK_H

#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<class T>
class Deck : public vector<shared_ptr<T>>{
public:
	//try to get the element on top
	shared_ptr<T> draw(){
		return this->back();
	};
};
#endif //!DECK_H