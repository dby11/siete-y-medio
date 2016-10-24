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
		bool win;
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
		Hand player_hand;
		cout << "Your cards: " << endl;
		cout << player_hand.get_card_rank(0) << " of " << player_hand.get_card_suit(0) << endl;
		cout << "Your total is " << player_hand.get_value() << endl;
		win = player_hand.play();

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