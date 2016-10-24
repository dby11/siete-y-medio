#include <string>
#include <vector>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;

	string get_english_suit() const;
	string get_english_rank() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	// A vector of Cards
	Hand();
	void add_card();
	double get_value();
	string get_english_rank(int m);
	string get_english_suit(int m);
	bool play();
	// You decide what functions you'll need...

private:
	vector<Card> deck;
	double hand_value;
	// You decide what fields you'll need...
};


class Player {
public:
	// Constructor. 
	//    Assigns initial amount of money
	Player();
	Player(int m);
	// You decide what functions you'll need...
	int get_money();
	void add_money(int m);
	void lose_money(int m);
private:
	int money;
	// You decide what extra fields (if any) you'll need...
};

#endif#pragma once
