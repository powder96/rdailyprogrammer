/**
 * Solution for the /r/dailyprogrammer/ challenge #115E (http://reddit.com/15ul7q/, http://reddit.com/pii6j/)
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

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>

int main() {
	std::cout << "Welcome to guess-that-numbers game! I have already picked a number in [1, 100]. "
	          << "Please make a guess. Type \"exit\" to quit." << std::endl;

	srand((unsigned int)time(NULL));
	const int number = 1 + (rand() % 100);

	std::string input;
	while(true) {
		std::cin >> input;

		if(input == "exit")
			break;

		int guess;
		if(!(std::stringstream(input) >> guess)) {
			std::cout << "This is not an integer or exit command." << std::endl;
			continue;
		}

		if(guess == number) {
			std::cout << "Correct! That is my number, you win!" << std::endl;
			break;
		}
		std::cout << "Wrong. That number is " << (guess < number ? "below" : "above") << " my number." << std::endl;
	}
}