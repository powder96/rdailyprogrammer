/**
 * Solution for the /r/dailyprogrammer/ challenge #122-2E (http://reddit.com/1aih0v/)
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


#include <fstream>
#include <iostream>
#include <string>

bool isWordWithOrderedNonRepeatedVowels(std::string& word) {
	const int vowelsTotal = 6;
	const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
	int expectedVowelIndex = 0;
	const int wordLength = word.length();
	for(int i = 0; i < wordLength; i++)
		for(int j = 0; j < vowelsTotal; j++)
			if(word[i] == vowels[j]) {
				if(j != expectedVowelIndex)
					return false;
				expectedVowelIndex++;
				break;
			}
	if(expectedVowelIndex != vowelsTotal)
		return false;
	return true;
}

void processWords(std::istream& input, std::ostream& output) {
	std::string word;
	while(!input.eof()) {
		input >> word;
		if(isWordWithOrderedNonRepeatedVowels(word))
			output << word << std::endl;
	}
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read world list" << std::endl;
		return 1;
	}

	processWords(input, std::cout);
}