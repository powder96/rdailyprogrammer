/**
 * Solution for the /r/dailyprogrammer/ challenge #130E (http://reddit.com/1givnn/)
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

#include <algorithm>
#include <ctime>
#include <iostream>

std::pair<int, int> readDiceNotation(std::istream& input) {
	std::pair<int, int> result;
	char d;
	input >> result.first >> d >> result.second;
	return result;
}

int rollDie(int faces) {
	return 1 + (rand() % faces);
}

void simulateAndPrintDieRolls(std::ostream& output, int times, int faces) {
	for(int i = 0; i < times; i++)
		output << rollDie(faces) << (i != (times - 1) ? " " : "");
	output << std::endl;
}

int main() {
	std::cout << "Format: \"<int:times>d<int:faces>\"" << std::endl;
	std::pair<int, int> notation = readDiceNotation(std::cin);
	srand((unsigned int)time(NULL));
	simulateAndPrintDieRolls(std::cout, notation.first, notation.second);
}