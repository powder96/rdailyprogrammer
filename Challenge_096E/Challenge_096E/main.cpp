/**
 * Solution for the /r/dailyprogrammer/ challenge #096E (http://reddit.com/zfe7v/)
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

unsigned int maxPS2Players(unsigned int budget) {
	const unsigned int controllerCost = 20;
	const unsigned int multitapCost = 12;
	const unsigned int multitapPorts = 4;

	unsigned int players = 1, availablePorts = 1;

	while(budget >= controllerCost) {
		if(availablePorts == 0) {
			budget -= multitapCost;
			availablePorts += multitapPorts - 1;
		}
		else {
			budget -= controllerCost;
			availablePorts--;
			players++;
		}
	}

	return players;
}

int main() {
	unsigned int budget;
	std::cout << "Format: \"<uint:budget>\"" << std::endl;
	std::cin >> budget;

	std::cout << "You can afford " << maxPS2Players(budget) << " people to play with you on one ps2." << std::endl;
}