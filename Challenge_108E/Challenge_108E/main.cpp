/**
 * Solution for the /r/dailyprogrammer/ challenge #108E (http://reddit.com/1268t4/)
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

#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

std::pair<float, int> toScientificNotation(float number) {
	const int exponent = (int)floor(log10(number));
	const float significand = number / pow(10.0f, exponent);
	return std::make_pair(significand, exponent);
}

int main(int argc, char** argv) {
	float number;
	bool makeRandomNumber = true;
	if(argc == 2) {
		std::stringstream argument(argv[1]);
		makeRandomNumber = !(argument >> number);
	}
	if(makeRandomNumber) {
		srand((unsigned int)time(NULL));
		number = 1.0f * rand() / RAND_MAX;
	}

	std::pair<float, int> scientificNotation = toScientificNotation(number);

	std::cout << scientificNotation.first << " * " << "10^" << scientificNotation.second;
}