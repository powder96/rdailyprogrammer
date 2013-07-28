/**
 * Solution for the /r/dailyprogrammer/ challenge #111E (http://reddit.com/12qi5b/)
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
#include <string>

std::string starDelete(std::string& input) {
	std::string output = "";
	int inputLength = (signed)input.length();
	for(int i = 0; i < inputLength; i++) {
		if(input[std::max(0, i - 1)] != '*' && input[i] != '*' && input[std::min(i + 1, inputLength - 1)] != '*')
			output += input[i];
	}
	return output;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}
	std::cout << starDelete(std::string(argv[1]));
}