/**
 * Solution for the /r/dailyprogrammer/ challenge #113E (http://reddit.com/13hmz3/)
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

enum Type {INT, FLOAT, DATE, STRING};

Type getType(std::string& value) {
	Type type = STRING;
	unsigned int dashesCount = 0;
	for(unsigned int i = 0; i < value.length(); i++) {
		if(i == 0 && (value[0] == '+' || value[0] == '-' || isdigit(value[0])))
			type = INT;
		else if((type == INT || type == DATE) && value[i] == '-') {
			type = DATE;
			dashesCount++;
		}
		else if(type == INT && value[i] == '.')
			type = FLOAT;
		else if((type == INT || type == FLOAT) && !isdigit(value[i]))
			type = STRING;
		if(type == DATE && dashesCount > 2)
			type = STRING;
		if(type == STRING)
			break;
	}
	if(type == INT && value.length() == 1 && !isdigit(value[0]))
		type = STRING;
	return type;
}

std::string typeToString(Type type) {
	switch(type) {
		case INT:
			return "int";
		case FLOAT:
			return "float";
		case DATE:
			return "date";
		case STRING:
			return "string";
		default:
			return "unknown";
	}
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <string:value>" << std::endl;
		return 1;
	}

	std::cout << typeToString(getType(std::string(argv[1])));
}