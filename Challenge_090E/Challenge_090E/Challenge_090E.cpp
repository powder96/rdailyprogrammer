/**
 * Solution for the /r/dailyprogrammer/ challenge #090E (http://reddit.com/ynw53/)
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
#include <list>

class StampBinaryImage {
	public:
		StampBinaryImage(std::istream& input) {
			input >> this->width;
			input >> this->height;
			this->image = new bool*[this->height];
			for(unsigned int y = 0; y < this->height; y++) {
				this->image[y] = new bool[this->width];
				for(unsigned int x = 0; x < this->width; x++)
					this->image[y][x] = false;
			}

			std::string drawingCommands;
			input >> drawingCommands;
			unsigned int drawingCommandsLength = drawingCommands.length();
			unsigned int x = 0, y = 0;
			for(unsigned int i = 0; i < drawingCommandsLength; i++) {
				switch(drawingCommands[i]) {
					case 'N':
						if(y > 0)
							y--;
						break;
					case 'S':
						if(y < this->height - 1)
							y++;
						break;
					case 'E':
						if(x < this->width - 1)
							x++;
						break;
					case 'W':
						if(x > 0)
							x--;
						break;
					case 'P':
						this->image[y][x] = true;
						break;
				}
			}
		}

		~StampBinaryImage() {
			for(unsigned int y = 0; y < this->height; y++)
				delete[] this->image[y];
			delete[] this->image;
		}

		void printAsASCIIArt(std::ostream& output) {
			for(unsigned int y = 0; y < this->height; y += 2) {
				for(unsigned int x = 0; x < this->width; x++) {
					const bool fill0 = this->image[y][x];
					const bool fill1 = (y + 1U < this->height) ? this->image[y + 1][x] : false;
					
					if(fill0 && fill1)
						output << (char)219;
					else if(!fill0 && fill1)
						output << (char)220;
					else if(fill0 && !fill1)
						output << (char)223;
					else // !fill0 && !fill1
						output << ' ';
				}
				output << std::endl;
			}
		}

	private:
		unsigned int width;
		unsigned int height;
		bool** image;
};

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read stamp image file" << std::endl;
		return 1;
	}

	StampBinaryImage image(input);
	image.printAsASCIIArt(std::cout);
}