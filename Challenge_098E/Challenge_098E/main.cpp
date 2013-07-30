/**
 * Solution for the /r/dailyprogrammer/ challenge #098E (http://reddit.com/zx8vw/)
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

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

void printArithmeticTable(std::ostream& output, char operation, unsigned int size) {
	const int columnWidth = 4;

	output << std::left << std::setw(columnWidth) << operation << "|";
	for(unsigned int i = 0; i <= size; i++)
		output << std::right << std::setw(columnWidth) << i;
	output << std::endl;

	output << std::string((size + 2) * columnWidth + 1, '-') << std::endl;

	for(unsigned int y = 0; y <= size; y++) {
		output << std::left << std::setw(columnWidth) << y << "|";
		for(unsigned int x = 0; x <= size; x++) {
			output << std::right << std::setw(columnWidth);
			switch(operation) {
				case '+':
					output << x + y;
					break;
				case '-':
					output << (signed)(x - y);
					break;
				case '*':
					output << x * y;
					break;
				case '/':
					if(y == 0)
						output << 'E';
					else
						output << x / y;
					break;
				case '%':
					if(y == 0)
						output << 'E';
					else
						output << x % y;
					break;
				default:
					output << 'E';
			}
		}
		output << std::endl;
	}
}

int main(int argc, char** argv) {
	if(argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <operation:+-*/> <uint:number>" << std::endl;
		return 1;
	}

	std::stringstream argument(argv[2]);
	unsigned int number;
	argument >> number;

	printArithmeticTable(std::cout, argv[1][0], number);
}