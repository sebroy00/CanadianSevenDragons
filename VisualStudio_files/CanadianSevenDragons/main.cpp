/*
main.cpp
Sebastien Roy
Nicolas Tremblay - 5992713
*/


#include <fstream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include"animalcard.h"
#include"nosplit.h"
#include"splittwo.h"
#include"splitfour.h"
#include"table.h"
#include"hand.h"
#include"player.h"
#include"exeptions.h"
#include"actioncard.h"  
#include"AnimalCardFactory.h"
#include"deck.h"


void TEST_classeTable() {
	Table table = Table();
	shared_ptr<NoSplit> sptr(new NoSplit('a'));
	shared_ptr<SplitTwo> sptrTWO(new SplitTwo('c', 'o'));
	shared_ptr<SplitTwo> sptrTHREE(new SplitTwo('o', 'c'));

	shared_ptr<SplitFour> sptr4a(new SplitFour('b', 'a', 'd', 'c'));
	shared_ptr<SplitFour> sptr4b(new SplitFour('a', 'b', 'c', 'd'));
	shared_ptr<SplitFour> sptr4c(new SplitFour('b', 'c', 'd', 'a'));
	shared_ptr<SplitFour> sptr4d(new SplitFour('c', 'd', 'a', 'b'));

	table.addAt(sptr, 5, 50);
	cout << table.addAt(sptr4a, 52, 53) << endl;
	cout << table.addAt(sptr, 52, 54) << endl;
	cout << table.addAt(sptr4d, 52, 55) << endl;
	table.printTable();
	cout << endl;
	cout << "before pick at" << endl;
	table.pickAt(52, 54);
	cout << "after pick at" << endl;
	table.printTable();
	cout << endl;
	cout << "add at count: " << table.addAt(sptr, 52, 54) << endl;
	cout << "after add at" << endl;
	table.printTable();
	cout << endl;

	cout << "add at count: " << table.addAt(sptr, 53, 54) << endl;
	cout << "after add at" << endl;
	table.printTable();
	cout << endl;


	char animal('a');
	if (table.win(animal))
		cout << "win";
}

void printHand(Hand h) {
	for (int c = 0; c < 3; c++) {
		for (int i = 0; i < h.noCards(); i++) {
			if (c == 0) {
				cout << i;
				string space = to_string(i).length() == 1 ? "  " : " ";
				cout << space;
			}
			if (c == 1) h[i]->printRow();
			if (c == 2) h[i]->printRow();
		}
		cout << endl;
	}
}

void TEST_classeHand() {
	Hand h = Hand();
	shared_ptr<NoSplit> sptr(new NoSplit('Q'));
	shared_ptr<NoSplit> sptr2(new NoSplit('P'));
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	printHand(h);
}

//changer de main

void TEST_ours(Table &_table, Player *p){

	BearAction *ba = new BearAction();
	//changer de main de 0 a 1
	for (int i = 0; i < 5; i++)
	{
		//joueur present seb
		QueryResult qr = ba->query();
		qr.nombreDeJoueurs = 2;
		qr.nomDuJoueur = "seb";

		cout << "Main 0:" << endl;
		printHand(p[0].hand);

		cout << "Main 1:" << endl;
		printHand(p[1].hand);

		ba->perform(_table, &p[0], qr);

		cout << "Main 0:" << endl;
		printHand(p[0].hand);

		cout << "Main 1:" << endl;
		printHand(p[1].hand);

		cout << "Fin de ours" << endl;
	}
	
}

void TEST_Moose(Table &_table, Player *p){
	MooseAction *ma = new MooseAction();
	QueryResult qr;
	qr.nombreDeJoueurs = 5;
	ma->perform(_table, p, qr);
}



void TEST_cerf(Table &_table, Player *p){

	//voir si on peut echanger la carte action d'un joueur a un autre
	DeerAction *da = new DeerAction();
	QueryResult qr;
	qr = da->query();
	qr.nombreDeJoueurs = 4;
	qr.nomDuJoueur = "seb";
	cout << p[1].getSecretAnimal()<<endl;
	cout << p[3].getSecretAnimal() << endl;
	da->perform(_table, p, qr);
	cout << p[1].getSecretAnimal() << endl;
	cout << p[3].getSecretAnimal() << endl;
}

//test loup et lievre
void TEST_Loup(Table & _table, Player *p){
	//Ajouter quelques cartes au tableau
	shared_ptr<AnimalCard> ac = shared_ptr<AnimalCard>(new SplitFour('b', 'd', 'h', 'm'));

	_table.addAt(ac, 51, 52);
	_table.printTable();

	_table.addAt(ac, 53, 52);

	shared_ptr<AnimalCard> animalTwo = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalThree = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFour = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFive = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));

	_table.addAt(animalTwo, 52, 51);
	_table.addAt(animalThree, 52, 50);
	_table.addAt(animalFour, 52, 49);
	_table.addAt(animalFive, 52, 48);

	_table.printTable();

	//tester les fonctions actions avec les cartes
	WolfAction *wa = new WolfAction();

	QueryResult qr = wa->query();
	while (!_table.get(qr.getX, qr.getY)){
		qr = wa->query();
	}
	qr.nomDuJoueur = "a";
	wa->perform(_table, &p[0], qr);
	printHand(p[0].hand);
	//HareAction *ha = new HareAction();
	//QueryResult qrr = ha->query();

	//while (!_table.get(qrr.getX, qrr.getY)){
	//	qrr = ha->query();
	//}

	//ha->perform(_table, &p[0], qrr);

	cout << "Fini query" << endl;
	//ba->perform(_table, &p[0], qr);
}

//void testActionCardConversion() {
//	vector<shared_ptr<AnimalCard> > a(10);
//
//	shared_ptr<ActionCard> ac(new ActionCard());
//
//	a.push_back(ac);
//
//
//	ActionCard new_ac = dynamic_cast<ActionCard&>(*a.back());
//
//	new_ac.test();
//}

int main() {
	vector<char> secretAnimals = { 'b','d','h','m','w' };

	/*shuffle device*/
	std::random_device rd;
	std::mt19937 mt(rd());

	int in_numPlayers;
	cout << "-------Preparation-------" << endl;
	cout << "Nombre de joueurs: ";
	cin >> in_numPlayers;
	cout << endl;
	/*on doit avoir un nombre entre 2 et 5*/
	in_numPlayers = in_numPlayers > 5 ? 5 : in_numPlayers;
	in_numPlayers = in_numPlayers < 2 ? 2 : in_numPlayers;

	/*shuffle the secret animals*/
	shuffle(secretAnimals.begin(), secretAnimals.end(), mt);

	/*create all players, in a vector*/
	vector<Player> players(in_numPlayers, Player('0'));
	
	/*create Deck of cards*/
	AnimalCardFactory acf = AnimalCardFactory();
	Deck<AnimalCard> deck = acf.getDeck();
	
	char a;

	string name;
	int playersCreated = 0;
	while (playersCreated < in_numPlayers) {
		players[playersCreated] = Player(secretAnimals[playersCreated]);
		cout << "Nom du joueur " << playersCreated << ": ";
		cin >> name;
		players[playersCreated].setName(name);
		players[playersCreated].hand += deck.draw();
		players[playersCreated].hand += deck.draw();
		players[playersCreated].hand += deck.draw();
		playersCreated++;
	}

	system("cls");

	bool winner(false);
	bool cardPlaced(false);
	bool playedAction(false);
	Table table = Table();
	string orientation;

	//TEST_actions(table, &players[0]);
	
	//TEST_ours(table, &players[0]);
	//TEST_Moose(table, &players[0]);

	//TEST_Loup(table, &players[0]);
	//TEST_cerf(table, &players[0]);

	while (!winner) {
		for (vector<Player>::iterator p = players.begin(); p != players.end(); p++) {
			/*imprime le nom du joueur*/
			cout << "Joueur: " << (*p).getName() << endl;
			/*imprime sa carte secrete*/
			cout << "Carte secrete: " << (*p).getSecretAnimal() << endl << endl;

			/*imprime la table*/
			cout << "Table: " << endl;
			cout << "------------------------" << endl;

			table.printTable();
			cout << endl;

			cout << "------------------------" << endl;

			/*imprime la hand du joueur*/
			cout << "Cartes: " << endl;
			printHand((*p).hand);
			cout << endl;

			int in_cardPosition, in_xCoord, in_yCoord, pickCards, in_changeOrientation;
			do {
				try {
					/*choisir la carte a utiliser*/
					cout << endl;
					cout << "Choix de carte (99 pour passer son tour): ";
					cin >> in_cardPosition;
					playedAction = false;

					if (in_cardPosition == 99)
						break;
					else if (in_cardPosition < (*p).hand.noCards() && in_cardPosition > -1) { //verif s'il y a vraiment une carte a cette position

						shared_ptr<AnimalCard> cardChoice = (*p).hand[in_cardPosition]; 
						AnimalCard* cardTest = cardChoice.get();

						/*essayer de faire un cast*/
						if (dynamic_cast<ActionCard*>(cardTest)) { /*essayer de faire le cast a un action card*/
							QueryResult qr;
							
							//voir quelle carte d'action a ete joue
							if (dynamic_cast<BearAction*>(cardTest)) {
								(*p).hand -= cardChoice;
								BearAction* ba = dynamic_cast<BearAction*>(cardTest);
								qr = ba->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								ba->perform(table, &players[0], qr);
							}
							else if (dynamic_cast<WolfAction*>(cardTest)) {

								WolfAction* wa = dynamic_cast<WolfAction*>(cardTest);
								qr = wa->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								while (!table.get(qr.getX, qr.getY)){
									qr = wa->query();
								}
								wa->perform(table, &players[0], qr);
								printHand(p->hand);
								(*p).hand -= cardChoice;
							}
							else if (dynamic_cast<HareAction*>(cardTest)) {

								HareAction* ha = dynamic_cast<HareAction*>(cardTest);
								qr = ha->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								while (!table.get(qr.getX, qr.getY)){
									qr = ha->query();
								}
								ha->perform(table, &p[0], qr);
								(*p).hand -= cardChoice;
							}
							else if (dynamic_cast<DeerAction*>(cardTest)) {

								DeerAction* da = dynamic_cast<DeerAction*>(cardTest);
								qr = da->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								da->perform(table, &players[0], qr);
								(*p).hand -= cardChoice;
								
							}
							else if (dynamic_cast<MooseAction*>(cardTest)) {
								MooseAction* ma = dynamic_cast<MooseAction*>(cardTest);
								qr = ma->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								ma->perform(table, &players[0], qr);
								(*p).hand -= cardChoice;
							}
							
							playedAction = true;
						}
						else {
							/*changer orientation*/
							cout << "Changer orientation de la carte? \n oui : 1 -- non : 0 \n";
							cin >> in_changeOrientation;
							if (in_changeOrientation == 1) {
								cout << "Quelle orientation? (D = DOWN ; U = UP)";
								cin >> orientation;
								cardChoice->setOrientation(orientation == "D" ? DOWN : UP);
							}

							/*imprime la carte (avec son changement d'orientation s'il y a lieu*/
							cout << "Carte choisie: ";
							cout << endl;
							cardChoice->printRow();
							cout << endl;
							cardChoice->printRow();
							cout << endl;

							/*placement de carte*/
							cout << "A quel endroit voulez vous placer la carte?" << endl;
							cout << "Coordonnee verticale:    ";
							cin >> in_xCoord;
							cout << "Coordonnee horizontale:  ";
							cin >> in_yCoord;

							/*ajouter carte sur la table*/
							pickCards = table.addAt(cardChoice, in_xCoord, in_yCoord);
							/*on enleve la carte de la hand du joueur*/
							(*p).hand -= cardChoice;

							/*pige les cartes du deck pour le mettre dans la hand du joueur d'apres la valeur retournee par addAt*/
							while (pickCards > 0) {
								(*p).hand += deck.draw();
								pickCards--;
							}

							/*le tour du joueur est fini*/
							cardPlaced = true;
						}
					}
					else {
						cout << "Aucune carte a cette position" << endl;
					}
				}
				catch (IllegalPlacement i) {
					i.report();
				}
			} while (!cardPlaced && !playedAction);

			/*Verification s'il y a un gagnant*/
			for (vector<Player>::iterator w = players.begin(); w != players.end() && !winner; w++) {
				a = (*w).getSecretAnimal();
				winner = table.win(a);
			}

			system("cls"); /*clear screen*/
			cardPlaced = false; /*reset les valeurs pour le prochain joueur*/
		}
	}
	/*trouver joueur gagnant*/ /*------------------------------------------------------*/
	cout << "winner: " << a;
	cout << "merci d'avoir joue!";
	system("pause");
	return 0;
}

