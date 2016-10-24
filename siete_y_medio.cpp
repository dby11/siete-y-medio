#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include <algorithm>
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	srand(time(0));
	int initial_amount;
	char c;
	bool play;
	cout << "Would you like to play? (y/n)" << endl;
	cin >> c;
	if (c == 'y')
		play = true;
	else
		play = false;
	cout << "How much money would you like to start with?" << endl;
	cin >> initial_amount;
	Player player(initial_amount);

	while (play) {
		int bet;
		cout << "You have $" << player.get_money() << ". Enter bet: " << endl;
		cin >> bet;
		while (true) {
			if (bet > (player.get_money())) {
				cout << "You don't have that much money! Please enter a new bet: ";
				cin >> bet;
			} else {
				break;
			}	
		}
		bool another_card = true;
		bool win;
		Hand player_hand;
		int counter = 0;
		cout << "Your cards: " << endl;
		cout << player_hand.get_card_rank(0) << " of " << player_hand.get_card_suit(0) << endl;
		cout << "Your total is " << player_hand.get_value() << endl;

		while (another_card) {
			if (player_hand.get_value() < 7.5) {
				cout << "Do you want another card (y/n)?";
			}
			else {
				cout << "You busted.";
				win = false;
				another_card = false;
				break;
			}
			c = '\0';
			cin >> c;
			if (c == 'y') {
				another_card = true;
				counter++;
			}
			else {
				another_card = false;
				break;
			}
			player_hand.add_card();
			cout << "Your cards: " << endl;

			cout << player_hand.get_card_rank(counter) << "of " << player_hand.get_card_suit(counter) << endl;
			cout << "Your total is " << player_hand.get_value() << endl;
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
				win = true;
				break;
			}
		}
		if (player_hand.get_value() < 7.5 && dealer_hand.get_value() < 7.5) {
			if ((7.5 - player_hand.get_value()) <= (7.5 - dealer_hand.get_value())) {
				win = true;
			} else {
				win = false;
			}
		}

		if (win) {
			cout << "You win $" << bet << endl;
			player.add_money(bet);
		} else {
			cout << "You lose $" << bet << endl;
			player.lose_money(bet);
		}

		cout << "Would you like to keep playing ? (y/n)";
		c = '\0';
		cin >> c;
		if (c == 'y')
			play = true;
		else
			play = false;
	}
	cout << "Hope you play again soon!" << endl;
	return 0;
}