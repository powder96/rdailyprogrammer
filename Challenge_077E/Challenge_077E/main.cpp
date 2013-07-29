/**
 * Solution for the /r/dailyprogrammer/ challenge #077E (http://reddit.com/wn3ld/)
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
#include <sstream>
#include <list>
#include <string>

void morse(std::list<std::string>& sequences, unsigned int size, std::string sequence = "") {
	if(size == 0)
		sequences.push_back(sequence);
	else {
		morse(sequences, size - 1, sequence + '.');
		if(size >= 2)
			morse(sequences, size - 2, sequence + '-');
	}
}

int main(int argc, char** argv) {
	unsigned int size = 10;
	if(argc == 2) {
		std::stringstream sizeStream(argv[1]);
		sizeStream >> size;
	}

	std::list<std::string> sequences;
	morse(sequences, size);

	if(sequences.size() <= 100)
		for(std::list<std::string>::iterator it = sequences.begin(); it != sequences.end(); it++)
			std::cout << *it << "  ";
	else
		std::cout << "List contains " << sequences.size() << " sequences";

	std::cout << std::endl;
}