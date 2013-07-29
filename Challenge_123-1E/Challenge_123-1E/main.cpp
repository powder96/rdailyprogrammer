/**
 * Solution for the /r/dailyprogrammer/ challenge #123-1E (http://reddit.com/1cdktg/,
 *                                                         http://reddit.com/1berjh/,
 *                                                         http://reddit.com/1cundw/)
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

unsigned int digitSum(unsigned int n) {
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

unsigned int digitalRoot(unsigned int n) {
	while(n >= 10)
		n = digitSum(n);
	return n;
}

int main() {
	unsigned int n;
	std::cout << "Format: \"<int>\"" << std::endl;
	std::cin >> n;

	std::cout << digitalRoot(n) << std::endl;
}