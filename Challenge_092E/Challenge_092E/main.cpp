/**
 * Solution for the /r/dailyprogrammer/ challenge #092E (http://reddit.com/ywlvf/)
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
#include <string>

const unsigned int sevenSegmentSpacing = 1;

const char sevenSegmentFonts[] = "\
+-+   + +-+ +-+ + + +-+ +-+ +-+ +-+ +-+ \
| |   |   |   | | | |   |     | | | | | \
| |   | +-+ +-+ +-+ +-+ +-+   | +-+ +-+ \
| |   | |     |   |   | | |   | | |   | \
+-+   + +-+ +-+   + +-+ +-+   + +-+ +-+ \
###   # ### ### # # ### ### ### ### ### \
# #   #   #   # # # #   #     # # # # # \
# #   # ### ### ### ### ###   # ### ### \
# #   # #     #   #   # # #   # # #   # \
###   # ### ###   # ### ###   # ### ### \
";

enum SevenSegmentFontCharacter {TL, TR, ML, MR, BL, BR, A, B, C, D, E, F, G};

char getSevenSegmentFontCharacter(unsigned int font, unsigned int digit, SevenSegmentFontCharacter character) {
	if(font >= 2)
		return ' ';
	unsigned int x, y;
	switch(character) {
		case TL: x = 0; y = 0; break;
		case TR: x = 2; y = 0; break;
		case ML: x = 0; y = 2; break;
		case MR: x = 2; y = 2; break;
		case BL: x = 0; y = 4; break;
		case BR: x = 2; y = 4; break;
		case A : x = 1; y = 0; break;
		case B : x = 2; y = 1; break;
		case C : x = 2; y = 3; break;
		case D : x = 1; y = 4; break;
		case E : x = 0; y = 3; break;
		case F : x = 0; y = 1; break;
		case G : x = 1; y = 2; break;
	}
	const int formatSymbolWidth = 4;
	const int formatLineWidth = formatSymbolWidth * 10;
	const int formatFontWidth = formatLineWidth * 5;
	return sevenSegmentFonts[(font * formatFontWidth) +
		(y * formatLineWidth) + (digit * formatSymbolWidth) + x];
}

void printSevenSegmentHorizontal(std::ostream& output, std::string& string, unsigned int font, unsigned int scale,
								 SevenSegmentFontCharacter jointL, SevenSegmentFontCharacter segment,
								 SevenSegmentFontCharacter jointR) {
	for(unsigned int i = 0; i < string.length(); i++) {
		if(!isdigit(string[i]))
			continue;
		const unsigned int digitIndex = string[i] - '0';
		output << getSevenSegmentFontCharacter(font, digitIndex, jointL)
		       << std::string(scale, getSevenSegmentFontCharacter(font, digitIndex, segment))
		       << getSevenSegmentFontCharacter(font, digitIndex, jointR)
		       << std::string(sevenSegmentSpacing * scale, ' ');
	}
	output << std::endl;
}

void printSevenSegmentVertical(std::ostream& output, std::string& string, unsigned int font, unsigned int scale,
							   SevenSegmentFontCharacter segmentL, SevenSegmentFontCharacter segmentR) {
								   
	for(unsigned int l = 0; l < scale; l++) {
		for(unsigned int i = 0; i < string.length(); i++) {
			if(!isdigit(string[i]))
				continue;
			const unsigned int digitIndex = string[i] - '0';
			output << getSevenSegmentFontCharacter(font, digitIndex, segmentL)
			       << std::string(scale, ' ')
			       << getSevenSegmentFontCharacter(font, digitIndex, segmentR)
			       << std::string(sevenSegmentSpacing * scale, ' ');
		}
		output << std::endl;
	}
}

void printSevenSegment(std::ostream& output, std::string& string, unsigned int font = 0, unsigned int scale = 1) {
	printSevenSegmentHorizontal(output, string, font, scale, TL, A, TR);
	printSevenSegmentVertical(output, string, font, scale, F, B);
	printSevenSegmentHorizontal(output, string, font, scale, ML, G, MR);
	printSevenSegmentVertical(output, string, font, scale, E, C);
	printSevenSegmentHorizontal(output, string, font, scale, BL, D, BR);
}

int main(int argc, char** argv) {
	if(argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <int:number> <uint:font> <uint:scale>" << std::endl;
		return 1;
	}

	std::stringstream arguments(std::string(argv[2]) + " " + std::string(argv[3]));
	unsigned int font, scale;
	arguments >> font >> scale;
	font = std::min((unsigned)1, font);
	scale = std::min((unsigned)5, scale);

	printSevenSegment(std::cout, std::string(argv[1]), font, scale);
}