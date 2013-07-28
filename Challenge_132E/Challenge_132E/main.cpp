/**
 * Solution for the /r/dailyprogrammer/ challenge #132E (http://reddit.com/1hvh6u/)
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

// https://en.wikipedia.org/wiki/Greatest_common_divisor#Using_Euclid.27s_algorithm
int gcd(float a, float b) {
	while(a != b) {
		if(a > b)
			a -= b;
		if(b > a)
			b -= a;
	}
	return (int)a;
}

int main() {
	int a, b;
	std::cout << "Format: \"<int> <int>\"" << std::endl;
	std::cin >> a >> b;

	std::cout << gcd(a * 1.0f, b * 1.0f) << std::endl;
}