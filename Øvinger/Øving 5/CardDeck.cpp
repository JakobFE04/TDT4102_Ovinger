#include "CardDeck.h"

// BEGIN: 3b
CardDeck::CardDeck(){
    for (int i=0; i<4; i++){
        for (int j=2; j<14; i++){
            Suit s = static_cast<Suit>(i);
            Rank r = static_cast<Rank>(j);
            Card c{s,r};
            cards.push_back(c);
        }
    }
}
// END: 3b

// BEGIN: 3c
void CardDeck::swap(int card_1, int card_2){
    iter_swap(cards.begin()+card_1, cards.begin()+card_2);
}
// END: 3c

// BEGIN: 3d
void CardDeck::print(){
    for(Card& c : cards){
        cout << c.toString() << endl;
    }
}
// END: 3d

// BEGIN: 3e
void CardDeck::shuffle(){
    auto rng = std::default_random_engine {};
    ranges::shuffle(cards, rng);
}
// END: 3e

// BEGIN: 3f
Card CardDeck::drawCard(){
    Card c = cards.back();
    cards.pop_back();
    return c;
}
// END: 3f
