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

void TEST_actions(Table &_table, Player *p){

	//Ajouter quelques cartes au tableau
	shared_ptr<AnimalCard> ac = shared_ptr<AnimalCard>(new SplitFour('b', 'd', 'h', 'm'));
	
	_table.addAt(ac, 51,52);
	_table.printTable();

	_table.addAt(ac, 53, 52);

	shared_ptr<AnimalCard> animalTwo = shared_ptr<AnimalCard>(new SplitTwo('b','d'));
	shared_ptr<AnimalCard> animalThree = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFour = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));
	shared_ptr<AnimalCard> animalFive = shared_ptr<AnimalCard>(new SplitTwo('b', 'd'));

	_table.addAt(animalTwo, 52, 51);
	_table.addAt(animalThree, 52, 50);
	_table.addAt(animalFour, 52, 49);
	_table.addAt(animalFive, 52, 48);
	
	_table.printTable();

	//tester les fonctions actions avec les cartes
	QueryResult qr;
	qr.nombreDeJoueurs = 2;
	qr.nomDuJoueur = "pat";
	qr.action = "nic";

	BearAction * ba = new BearAction();
	ba->perform(_table, &p[0], qr);
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
vector<char> secretAnimals = { 'b','d','h','m','w' };
int main() {
	//testActionCardConversion();
	int in_numPlayers;
	cout << "-------Preparation-------" << endl;
	cout << "Nombre de joueurs: ";
	cin >> in_numPlayers;
	cout << endl;
	/*on doit avoir un nombre entre 2 et 5*/
	in_numPlayers = in_numPlayers > 5 ? 5 : in_numPlayers;
	in_numPlayers = in_numPlayers < 2 ? 2 : in_numPlayers;

	/*shuffle the secret animals*/
	random_shuffle(secretAnimals.begin(), secretAnimals.end());

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
	Table table = Table();

	TEST_actions(table, &players[0]);
	
	while (!winner) {
		for (vector<Player>::iterator p = players.begin(); p != players.end(); p++) {
			cout << "Joueur: " << (*p).getName() << endl << endl;

			cout << "Table: " << endl;
			cout << "------------------------" << endl;

			table.printTable();
			cout << endl;

			cout << "------------------------" << endl;

			cout << "Cartes: " << endl;
			printHand((*p).hand);
			cout << endl;

			bool cardPlaced = false;
			int cardPosition, xCoord, yCoord, pickCards, changeOrientation;
			do {
				try {
					cout << endl;
					cout << "Carte secrete: " << (*p).getSecretAnimal() << endl;
					cout << "Choix de carte: ";
					cin >> cardPosition;
					if (cardPosition < (*p).hand.noCards() && cardPosition > -1) { //verif s'il y a vraiment une carte a cette position
						
						shared_ptr<AnimalCard> cardChoice = (*p).hand[cardPosition]; \
						AnimalCard* cardTest = cardChoice.get();

						//essayer de faire un cast
						if (dynamic_cast<ActionCard*>(cardTest)) { //essayer de faire le cast a un action card
							QueryResult qr;
							qr.nombreDeJoueurs = in_numPlayers;
							qr.nomDuJoueur = p->getName();
							//voir quelle carte d'action a ete joue
							if (dynamic_cast<BearAction*>(cardTest)){
								BearAction* ba = dynamic_cast<BearAction*>(cardTest); 
								qr = ba->query();
								ba->perform(table, &players[0], qr);
							}
							else if (dynamic_cast<WolfAction*>(cardTest)){
								//enlever une carte du la table
								WolfAction* ba = dynamic_cast<WolfAction*>(cardTest);
								qr = ba->query();
								bool validCard = false;
								while (!validCard){
									if (table.get(qr.getX, qr.getY)){
										validCard = true;
									}
									else{
										qr = ba->query();
									}
								}
								ba->perform(table, &players[0], qr);
							}
							else if (dynamic_cast<HareAction*>(cardTest)){
								HareAction* ha = dynamic_cast<HareAction*>(cardTest);
								qr = ha->query();
								table.addAt(table.get(qr.getX, qr.getY), qr.endX, qr.endY);
							}
							else if (dynamic_cast<DeerAction*>(cardTest)){
								DeerAction* da = dynamic_cast<DeerAction*>(cardTest);
								qr = da->query();
								da->perform(table, &players[0], qr);
							}else if (dynamic_cast<MooseAction*>(cardTest)){
								MooseAction* ma = dynamic_cast<MooseAction*>(cardTest);
								qr = ma->query();
								ma->perform(table, &players[0], qr);
							}
							cout << "Action Card Selected" << endl;
						}
						else {
							cout << "Changer orientation de la carte? \n oui : 1 -- non : 0 \n";
							cin >> changeOrientation;
							if (changeOrientation == 1) {
								cardChoice->setOrientation(DOWN);
							}
							cout << "Carte choisie: ";
							cout << endl;
							cardChoice->printRow();
							cout << endl;
							cardChoice->printRow();
							cout << endl;
							cout << "A quel endroit voulez vous placer la carte?" << endl;
							cout << "Coordonnee verticale:    ";
							cin >> xCoord;
							cout << "Coordonnee horizontale:  ";
							cin >> yCoord;
							pickCards = table.addAt(cardChoice, xCoord, yCoord);
							(*p).hand -= cardChoice; /*on enleve la carte selectionnee*/
							while (pickCards > 0) {
								(*p).hand += deck.draw(); /*pige les cartes d'apres la valeur retournee par addAt*/
								pickCards--;
							}
							cardPlaced = true; /*tour est fini*/
						}
					}
					else {
						cout << "Aucune carte a cette position" << endl;
					}
				}
				catch (IllegalPlacement i) {
					i.report();
				}
			} while (!cardPlaced);
			/*Verification s'il y a un gagnant*/
			for (vector<Player>::iterator w = players.begin(); w != players.end() && !winner; w++) {
				a = (*w).getSecretAnimal();
				winner = table.win(a);
			}
			system("cls");
			cardPlaced = false;
		}
	}
	//array of players ? PROBLEM : different secretCards

	cout << "winner: " << a; 





	return 0;
}

