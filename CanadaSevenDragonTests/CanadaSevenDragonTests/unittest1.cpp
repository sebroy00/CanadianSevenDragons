#include "stdafx.h"
#include "CppUnitTest.h"

#include "C:\Users\Nicolas\Documents\CSI2772\projet\CanadianSevenDragons\VisualStudio_files\CanadianSevenDragons\AnimalCardFactory.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CanadaSevenDragonTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//get an animal card factory
		AnimalCardFactory *ac = new AnimalCardFactory();
		Deck<AnimalCard> deck = ac->getDeck();
		int in_numPlayers = 2;

		vector<Player> players(in_numPlayers, Player('0'));
		//draw all the cards and test the actions

		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}

	};
}