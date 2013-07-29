/**
 * Solution for the /r/dailyprogrammer/ challenge #076E (http://reddit.com/wjzly/)
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
#include <iostream>
#include <sstream>
#include <list>
#include <string>

std::string titleCase(std::string phrase, std::list<std::string>& exceptions) {
	std::string result = "";

	if(phrase.empty())
		return result;

	std::stringstream phraseStream(phrase);
	while(phraseStream.good()) {
		std::string word;
		phraseStream >> word;
		std::transform(word.begin(), word.end(), word.begin(), tolower);
		if(result.empty() || std::find(exceptions.begin(), exceptions.end(), word) == exceptions.end())
			word.replace(0, 1, std::string(1, toupper(word[0])));
		result += word + ' ';
	}
	result.erase(result.length() - 1);

	return result;
}

int main(int argc, char** argv) {
	if(argc == 1) {
		std::cerr << "Usage: " << argv[0] << " <string:titlecase> [<string:exception1>, [...]]" << std::endl;
		return 1;
	}

	std::string phrase = argv[1];

	std::list<std::string> exceptions;
	for(int i = 2; i < argc; i++)
		exceptions.push_back(std::string(argv[i]));

	std::cout << titleCase(phrase, exceptions);
}