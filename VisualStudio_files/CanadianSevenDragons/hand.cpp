#include "hand.h"

Hand & Hand::operator+=(std::shared_ptr<AnimalCard> card) {
	a.push_back(card);
	return (*this);
}

Hand & Hand::operator-=(std::shared_ptr<AnimalCard> card) {
	int lengthBefore = a.size();
	a.remove(card);
	if (a.size() < lengthBefore)
		throw new exception(); //a modifier
	return (*this);
}

std::shared_ptr<AnimalCard>& Hand::operator[](int position) {
	auto vi = a.begin();
	std::advance(vi, position);
	return *vi;
}

int Hand::noCards() {
	return a.size();
}