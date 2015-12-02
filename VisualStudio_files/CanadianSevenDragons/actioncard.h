#include <iostream>
#include"nosplit.h"
#include "table.h"
#include "player.h"

#ifndef ACTIONCARD_H
#define ACTIONCARD_H

using namespace std;

struct QueryResult{
	string action;
	string getX, getY;
};

class ActionCard : public NoSplit {
public:
	ActionCard(char c) : NoSplit(c) {};
	virtual QueryResult query() = 0;
	virtual void perform(Table&, Player*, QueryResult) = 0;
};

class BearAction : public ActionCard {
public:
	BearAction() : ActionCard('B') {};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class DeerAction : public ActionCard {
public:
	DeerAction() : ActionCard('D') {};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class MooseAction : public ActionCard {
public:
	MooseAction() : ActionCard('M') {};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class WolfAction : public ActionCard {
public:
	WolfAction() : ActionCard('W') {};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class HareAction : public ActionCard {
public:
	HareAction() : ActionCard('H') {};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

#endif // !ACTIONCARD_H