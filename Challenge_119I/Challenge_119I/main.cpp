/**
 * Solution for the /r/dailyprogrammer/ challenge #119I (http://reddit.com/17jvoh/)
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

class Maze {
	public:
		Maze(std::istream& input) {
			input >> this->size;
			this->map = new Cell*[this->size];
			for(unsigned int y = 0; y < this->size; y++) {
				this->map[y] = new Cell[this->size];
				for(unsigned int x = 0; x < this->size; x++) {
					char c;
					input >> c;
					if(c == '.')
						this->map[y][x] = EMPTY;
					else if(c == 'W')
						this->map[y][x] = WALL;
					else if(c == 'S')
						this->map[y][x] = START;
					else // c == 'E'
						this->map[y][x] = END;
				}
			}
		}

		~Maze() {
			for(unsigned int y = 0; y < this->size; y++)
				delete[] this->map[y];
			delete[] this->map;
		}

		int findMinimalPathCost() {
			std::pair<int, int> mazeStart = this->findCell(START);
			std::pair<int, int> mazeEnd = this->findCell(END);

			const int undefinedCost = -1;
			int** costMap = new int*[this->size];
			for(unsigned int y = 0; y < this->size; y++) {
				costMap[y] = new int[this->size];
				for(unsigned int x = 0; x < this->size; x++)
					costMap[y][x] = undefinedCost;
			}

			std::list<std::pair<int, int>> currentWave;
			std::list<std::pair<int, int>> nextWave;

			int currentWaveCost = 0;
			costMap[mazeStart.second][mazeStart.first] = 0;
			nextWave.push_back(mazeStart);

			const int adjacentCellsCount = 4;
			const int adjacentCellsDeltaX[] = {-1,  0, 1, 0};
			const int adjacentCellsDeltaY[] = { 0, -1, 0, 1};

			int mazeEndCost = undefinedCost;
			while(!nextWave.empty() && mazeEndCost == undefinedCost) {
				currentWave = nextWave;
				currentWaveCost++;
				nextWave.clear();

				for(std::list<std::pair<int, int>>::iterator it = currentWave.begin();
						it != currentWave.end() && mazeEndCost == undefinedCost; it++) {
					for(int i = 0; i < adjacentCellsCount; i++) {
						int x = it->first  + adjacentCellsDeltaX[i];
						int y = it->second + adjacentCellsDeltaY[i];
						std::pair<int, int> cell(x, y);

						if(x < 0 || (unsigned)x >= this->size || y < 0 || (unsigned)y >= this->size)
							continue;

						if(this->map[y][x] != WALL && costMap[y][x] == undefinedCost) {
							costMap[y][x] = currentWaveCost;
							nextWave.push_back(cell);

							if(cell == mazeEnd) {
								mazeEndCost = currentWaveCost;
								break;
							}
						}
					}
				}
			}

			for(unsigned int y = 0; y < this->size; y++)
				delete[] costMap[y];
			delete[] costMap;

			return mazeEndCost;
		}

	private:
		unsigned int size;
		enum Cell {EMPTY = 0, WALL, START, END};
		Cell** map;

		std::pair<int, int> findCell(Cell cell) {
			for(unsigned int y = 0; y < this->size; y++)
				for(unsigned int x = 0; x < this->size; x++)
					if(this->map[y][x] == cell)
						return std::make_pair(x, y);
			return std::make_pair(-1, -1);
		}
};

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read maze file" << std::endl;
		return 1;
	}

	Maze maze(input);
	int minimalPathCost = maze.findMinimalPathCost();
	
	if(minimalPathCost == -1)
		std::cout << "False" << std::endl;
	else
		std::cout << "True, " << minimalPathCost << std::endl;
}