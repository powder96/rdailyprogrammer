/**
 * Solution for the /r/dailyprogrammer/ challenge #119E (http://reddit.com/17f3y2/)
 * Copyright (C) 2013 powder96 <https://github.com/powder96/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

struct Coin {
	char* namePlural;
	float value;
};
static const int coinsTotal = 4;
static const Coin coins[] = {
	{"Quarters", 0.25f},
	{"Dimes",    0.10f},
	{"Nickels",  0.05f},
	{"Pennies",  0.01f}
};

void printCoins(std::ostream& output, float dollars) {
	for(int i = 0; i < coinsTotal; i++) {
		int coinTotal = (int)(dollars / coins[i].value);
		dollars -= coinTotal * coins[i].value;
		if(coinTotal > 0)
			output << coins[i].namePlural << ": " << coinTotal << std::endl;
	}
}

int main() {
	float dollars;
	std::cout << "Format: \"<float:dollars>\"" << std::endl;
	std::cin >> dollars;
	printCoins(std::cout, dollars);
}