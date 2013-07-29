/**
 * Solution for the /r/dailyprogrammer/ challenge #129E (http://reddit.com/1g0tw1/)
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

std::string longestTwoCharSubstr(std::string& input) {
	std::string longestSubstr = "";
	int inputLength = (signed)input.length();
	for(int i = 0; i < inputLength; i++) {
		std::string substr = "";
		char first, second;
		bool secondCharDefined = false;
		for(int j = 0; i + j < inputLength; j++) {
			if(j == 0)
				first = input[i + j];
			else if(!secondCharDefined && input[i + j] != first) {
				second = input[i + j];
				secondCharDefined = true;
			}
			else
				if(input[i + j] != first && input[i + j] != second)
					break;
			substr += input[i + j];
		}
		if(substr.length() > longestSubstr.length())
			longestSubstr = substr;
	}
	return longestSubstr;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}
	std::cout << longestTwoCharSubstr(std::string(argv[1]));
}