/**
 * Solution for the /r/dailyprogrammer/ challenge #086E (http://reddit.com/xxbbo/)
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
#include <list>
#include <string>

std::string rleCompress(std::string data) {
	std::list<std::pair<char, int>> runs;
	char character;
	int instances;
	for(unsigned int i = 0; i < data.length(); i++) {
		if(i == 0 || data[i] != character) {
			if(i != 0)
				runs.push_back(std::make_pair(character, instances));
			character = data[i];
			instances = 1;
		}
		else
			instances++;
		if(i == data.length() - 1)
			runs.push_back(std::make_pair(character, instances));
	}
	
	std::string output = "";
	for(std::list<std::pair<char, int>>::iterator it = runs.begin(); it != runs.end(); it++) {
		int instances = it->second;
		while(instances > 0) {
			int i = std::min(instances, 255);
			instances -= i;
			output += (char)i;
			output += it->first;
		}
	}
	return output;
}

std::string rleDecompress(std::string data) {
	std::string output = "";
	for(unsigned int i = 0; i < data.length(); i += 2)
		output += std::string((int)(unsigned char)data[i], data[i + 1]);
	return output;
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cout << "Usage: " << argv[0] << " <mode:compress|decompress> <filename>" << std::endl;
		return 1;
	}

	bool compress = strcmp(argv[1], "compress") == 0;

	std::ifstream input(argv[2]);
	if(!input.good()) {
		std::cout << "Cannot read file" << std::endl;
		return 1;
	}
	std::string data((std::istreambuf_iterator<char>(input)), (std::istreambuf_iterator<char>()));

	if(compress)
		std::cout << rleCompress(data);
	else
		std::cout << rleDecompress(data);
}