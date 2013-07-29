/**
 * Solution for the /r/dailyprogrammer/ challenge #110E (http://reddit.com/12k3xr/)
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
#include <list>
#include <string>

void replaceCharacters(std::string& string, char rules[]) {
	const int rulesCount = strlen(rules) / 2;
	for(unsigned int i = 0; i < string.length(); i++) {
		for(int j = 0; j < rulesCount; j++)
			if(string[i] == rules[j * 2]) {
				string.replace(i, 1, std::string(1, rules[j * 2 + 1]));
				break;
			}
	}
}


int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}

	char rules[] = "\
wqewretrytuyiuoipo[p\
WQEWRETRYTUYIUOIPO{P\
sadsfdgfhgjhkjlk;l';\
SADSFDGFHGJHKJLK:L\":\
xzcxvcbvnbmn,m.,/.\
XZCXVCBVNBMN<M><?>\
";
	std::string result(argv[1]);
	replaceCharacters(result, rules);
	std::cout << result;
}