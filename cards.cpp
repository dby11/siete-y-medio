#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "coins";
		break;
	case COPAS:
		suitName = "cups";
		break;
	case ESPADAS:
		suitName = "spades";
		break;
	case BASTOS:
		suitName = "clubs";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "Ace";
		break;
	case DOS:
		rankName = "Two";
		break;
	case TRES:
		rankName = "Three";
		break;
	case CUATRO:
		rankName = "Four";
		break;
	case CINCO:
		rankName = "Five";
		break;
	case SEIS:
		rankName = "Six";
		break;
	case SIETE:
		rankName = "Seven";
		break;
	case SOTA:
		rankName = "Jack";
		break;
	case CABALLO:
		rankName = "Knight";
		break;
	case REY:
		rankName = "King";
		break;
	default: break;
	}
	return rankName;;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

double Card::get_value() const {
	if ((*this).get_rank() >= 10)
		return 0.5;
	else
		return (*this).get_rank();
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}


/* Hand Class*/

Hand::Hand() {
	Card first_card;
	deck.push_back(first_card);
	hand_value = first_card.get_value();
}

void Hand::add_card() {
	Card new_card;
	(*this).deck.push_back(new_card);
	hand_value += new_card.get_value();
}

double Hand::get_value() {
	return static_cast<double> ((*this).hand_value);
}

string Hand::get_card_suit(int m) {
	return ((*this).deck[m].get_english_suit());
}

string Hand::get_card_rank(int m) {
	return (*this).deck[m].get_english_rank();
}

bool Hand::play() {
	int counter = 0;
	bool another_card = true;
	while (another_card) {
		char c;
		if ((*this).get_value() < 7.5) {
			cout << "Do you want another card (y/n)?";
		}
		else {
			cout << "You busted.";
			return false;
		}
		cin >> c;
		if (c == 'y') {
			another_card = true;
			counter++;
		}
		else {
			another_card = false;
			break;
		}
		(*this).add_card();
		cout << "Your cards: " << endl;

		cout << (*this).get_card_rank(counter) << "of " << (*this).get_card_suit(counter) << endl;
		cout << "Your total is " << (*this).get_value() << endl;
	}

	Hand dealer_hand;
	int dealer_counter = 0;
	cout << "Dealer cards: " << endl;
	cout << dealer_hand.get_card_rank(0) << " of " << dealer_hand.get_card_suit(0) << endl;
	cout << "Dealer total is " << dealer_hand.get_value() << ".";

	while (dealer_hand.get_value() < 5.5) {

		dealer_counter++;
		dealer_hand.add_card();
		cout << "Dealer cards: " << endl;

		cout << dealer_hand.get_card_rank(dealer_counter) << "of " << dealer_hand.get_card_suit(dealer_counter) << endl;
		cout << "Dealer total is " << dealer_hand.get_value() << ".";
		if (dealer_hand.get_value() > 7.5) {
			cout << "Dealer busted.";
			return true;
		}
	}
	if ((*this).get_value() <= 7.5 && dealer_hand.get_value() <= 7.5) {
		if ((7.5 - (*this).get_value()) <= (7.5 - dealer_hand.get_value())) {
			return true;
		}
		else {
			return false;
		}
	}
}



/* *************************************************
Player class
************************************************* */
//Default constructor
Player::Player() {
	money = 100;
}

Player::Player(int pesos) {
	money = pesos;
}

//Gets the amount of money the player has
int Player::get_money() {
	return money;
}

//Updates the amount of money the player has
void Player::add_money(int update) {
	money += update;
	return;
}

void Player::lose_money(int update) {
	money -= update;
	return;
}
