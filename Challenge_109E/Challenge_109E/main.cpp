/**
 * Solution for the /r/dailyprogrammer/ challenge #109E (http://reddit.com/12csk7/)
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

bool isNumeric(std::string& string) {
	unsigned int stringLength = string.length();
	for(unsigned int i = 0; i < stringLength; i++) {
		if(!isdigit(string[i]))
			return false;
	}
	return true;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}
	std::cout << (isNumeric(std::string(argv[1])) ? "true" : "false");
}