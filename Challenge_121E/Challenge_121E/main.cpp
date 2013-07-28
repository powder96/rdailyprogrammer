/**
 * Solution for the /r/dailyprogrammer/ challenge #121E (http://reddit.com/19mn2d/)
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

unsigned int exchange(unsigned int coin) {
	if(coin == 0)
		return 1;
	return exchange(coin / 2) + exchange(coin / 3) + exchange(coin / 4);
}

int main() {
	unsigned int coin;
	std::cout << "Format: \"<int:coin>\"" << std::endl;
	std::cin >> coin;

	std::cout << exchange(coin) << std::endl;
}