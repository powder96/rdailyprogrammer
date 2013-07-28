/**
 * Solution for the /r/dailyprogrammer/ challenge #117E (http://reddit.com/16jiuq/)
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
#include <iomanip>

static const int lineLength = 16;

void hexDump(std::istream& input, std::ostream& output) {
	int lineNumber = 0, byteNumber = 0;
	char szLineASCII[lineLength + 1];
	szLineASCII[lineLength] = '\0';
	output << std::hex << std::setfill('0') << std::uppercase;
	while(!input.eof() || byteNumber > 0) {
		if(byteNumber == 0)
			output << std::setw(8) << lineNumber << " ";
		const int byte = input.get();
		if(input.good()) {
			output << " " << std::setw(2) << byte;
			if(byte >= ' ' && byte <= '~')
				szLineASCII[byteNumber] = (char)byte;
			else
				szLineASCII[byteNumber] = '.';
		}
		else {
			output << "   ";
			szLineASCII[byteNumber] = ' ';
		}
		if((++byteNumber) == lineLength) {
			byteNumber = 0;
			lineNumber++;
			output << "  " << szLineASCII << std::endl;
		}
	}
	if(byteNumber != 16)
		output << std::endl;
}

int main(int argc, char** argv) {
	char* filename;
	if(argc == 2)
		filename = argv[1];
	else
		filename = argv[0];

	std::ifstream input(filename, std::ios::binary);
	if(!input.good()) {
		std::cerr << "Cannot read input file" << std::endl;
		return 1;
	}

	hexDump(input, std::cout);
}