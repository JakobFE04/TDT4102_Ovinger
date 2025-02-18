#pragma once
#include "Card.h"

// BEGIN: 3a
class CardDeck{
private:
    
public:
    vector<Card> cards;
    CardDeck();
    void swap(int card_1, int card_2);
    void print();
    void shuffle();
    Card drawCard();
};
// END: 3a
 