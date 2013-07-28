/**
 * Solution for the /r/dailyprogrammer/ challenge #127E (http://reddit.com/1f7qp5/)
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

int mcCarthy91(std::ostream& log, int n) {
	if(n > 100) {
		n -= 10;
		log << "M(" << n << ") since " << n << " is greater than 100"
		    << std::endl;
		return n;
	}
	n += 11;
	log << "M(M(" << n << ")) since " << n << " is equal to or less than 100"
	    << std::endl;
	return mcCarthy91(log, mcCarthy91(log, n));
}

int main() {
	int n;
	std::cout << "Format: \"<int>\"" << std::endl;
	std::cin >> n;

	std::cout << "M(" << n << ")" << std::endl;
	std::cout << mcCarthy91(std::cout, n) << std::endl;
}