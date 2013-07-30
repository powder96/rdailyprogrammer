/**
 * Solution for the /r/dailyprogrammer/ challenge #088E (http://reddit.com/y5sox/)
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

void toUppercase(std::string& string) {
	for(unsigned int i = 0; i < string.length(); i++)
		string[i] = toupper(string[i]);
}

std::string vigenereEncrypt(std::string message, std::string key) {
	toUppercase(message);
	toUppercase(key);
	for(unsigned int i = 0; i < message.length(); i++) {
		if(message[i] < 'A' || message[i] > 'Z')
			continue;
		int sum = (message[i] - 'A') + (key[i % key.length()] - 'A');
		if(sum < 0)
			sum += 26;
		if(sum >= 26)
			sum -= 26;
		message[i] = ('A' + sum);
	}
	return message;
}

std::string vigenereDecrypt(std::string message, std::string key) {
	toUppercase(message);
	toUppercase(key);
	for(unsigned int i = 0; i < message.length(); i++) {
		if(message[i] < 'A' || message[i] > 'Z')
			continue;
		int sum = (message[i] - 'A') - (key[i % key.length()] - 'A');
		if(sum < 0)
			sum += 26;
		if(sum >= 26)
			sum -= 26;
		message[i] = ('A' + sum);
	}
	return message;
}

int main(int argc, char** argv) {
	if(argc != 4) {
		std::cout << "Usage: " << argv[0] << " <mode:encrypt|decrypt> <filename> <key>" << std::endl;
		return 1;
	}

	bool encrypt = strcmp(argv[1], "encrypt") == 0;

	std::ifstream input(argv[2]);
	if(!input.good()) {
		std::cout << "Cannot read message file" << std::endl;
		return 1;
	}
	std::string message = "";
	input >> message;

	std::string key(argv[3]);

	if(encrypt)
		std::cout << vigenereEncrypt(message, key);
	else
		std::cout << vigenereDecrypt(message, key);
}