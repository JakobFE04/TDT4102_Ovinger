#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

int main()
{
	cout << "What function? ";
	int input;
	cin >> input;
	switch(input){
		case 1:
			/*Rank R = Rank::king;
			Suit S = Suit::hearts;
			string rank = rankToString(R);
			string suit = suitToString(S);
			cout << "Rank: " << rank << " Suit: " << suit << endl;
			break;*/
		case 2:
			/*Card c{Suit::spades, Rank::ace};
			cout << c.toString() << '\n';
			break;*/
		case 3:
			CardDeck cardDeck{};
			cardDeck.print();
			/*cardDeck.swap(3,4);
			cout << " ----------------- " << endl;
			cardDeck.print();
			cout << " ----------------- " << endl;
			cardDeck.shuffle();
			cardDeck.print();*/
	}
	return 0;
}