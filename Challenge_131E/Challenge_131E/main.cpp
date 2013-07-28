/**
 * Solution for the /r/dailyprogrammer/ challenge #131E (http://reddit.com/1heozl/)
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

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>

static const int testDataMaxLength = 1024;

void reverse(char* string) {
	int length = strlen(string);
	for(int i = 0; i < length / 2; i++)
		std::swap(string[i], string[(length - 1) - i]);
}

void toUppercase(char* string) {
	int length = strlen(string);
	for(int i = 0; i < length; i++)
		string[i] = toupper(string[i]);
}

void processTests(std::istream& input, std::ostream& output) {
	int totalTests;
	input >> totalTests;
	for(int i = 0; i < totalTests; i++) {
		int testIndex;
		char testData[testDataMaxLength];
		char testExpectedData[testDataMaxLength];
		input >> testIndex >> testData >> testExpectedData;
		if(testIndex == 0)
			reverse(testData);
		else
			toUppercase(testData);
		if(strcmp(testData, testExpectedData) == 0)
			output << "Good test data" << std::endl;
		else
			output << "Mismatch! Bad test data" << std::endl;
	}
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read test file" << std::endl;
		return 1;
	}

	processTests(input, std::cout);
}