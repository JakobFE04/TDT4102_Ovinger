#pragma once
#include "std_lib_facilities.h"

// BEGIN: 1a
enum class Suit {clubs, diamonds, hearts, spades};
// END: 1a

// BEGIN: 1b
enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
// END: 1b


// Les deg opp på map og unordered_map i C++, og bruk disse map-ene 
// for å konvertere mellom Rank/Suit og string i oppgavene videre
// Husk å fjern /* for å bruke map-ene
const map<Rank, string> rankToStringMap {
	{Rank::two, "Two"},
	{Rank::three, "Three"},
	{Rank::four, "Four"},
	{Rank::five, "Five"},
	{Rank::six, "Six"},
	{Rank::seven, "Seven"},
	{Rank::eight, "Eight"},
	{Rank::nine, "Nine"},
	{Rank::ten, "Ten"},
	{Rank::jack, "Jack"},
	{Rank::queen, "Queen"},
	{Rank::king, "King"},
	{Rank::ace, "Ace"}
};

const map<Suit, string> SuitToStringMap {
	{Suit::clubs, "Clubs"},
	{Suit::diamonds, "Diamonds"},
	{Suit::hearts, "Hearts"},
	{Suit::spades, "Spades"}
};


// BEGIN: 1c
string suitToString(Suit input);
// END: 1c

// BEGIN: 1d
string rankToString(Rank input);
// END: 1d

// BEGIN: 2a
class Card {
private:
	Suit s;
	Rank r;
public:
	Card(Suit suit, Rank rank);
	Suit getSuit();
	Rank getRank();
	string toString();
};
// END: 2a