
#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include"nosplit.h"
#include "table.h"
#include "player.h"

using namespace std;

struct QueryResult{
	string action;
	string getX, getY;
};

class ActionCard : public NoSplit {
public:
	ActionCard(){};
	virtual QueryResult query() = 0;
	virtual void perform(Table&, Player*, QueryResult) = 0;
};

class BearAction : public ActionCard {
public:
	BearAction(){};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class DeerAction : public ActionCard {
public:
	DeerAction(){};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class MooseAction : public ActionCard {
public:
	MooseAction(){};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class WolfAction : public ActionCard {
public:
	WolfAction(){};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

class HareAction : public ActionCard {
public:
	HareAction(){};
	QueryResult query();
	void perform(Table&, Player*, QueryResult);
};

#endif // !ACTIONCARD_H