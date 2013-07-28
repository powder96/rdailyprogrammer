/**
 * Solution for the /r/dailyprogrammer/ challenge #128I (http://reddit.com/1g7gyi/)
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

class MatrixCity {
	public:
		MatrixCity(std::istream& input) {
			input >> this->size;
			this->map = new int*[this->size];
			for(unsigned int y = 0; y < this->size; y++) {
				this->map[y] = new int[this->size];
				for(unsigned int x = 0; x < this->size; x++)
					input >> this->map[y][x];
			}
		}

		~MatrixCity() {
			for(unsigned int y = 0; y < this->size; y++)
				delete[] this->map[y];
			delete[] this->map;
		}

		void printRepairLog(std::ostream& output) {
			for(std::list<StreetRepair>::iterator it = this->repairLog.begin();
			    it != this->repairLog.end(); it++)
				output << (it->first == ROW ? "Row " : "Column ") << it->second
				       << " repaired." << std::endl;
		}

		void printMap(std::ostream& output) {
			for(unsigned int y = 0; y < this->size; y++) {
				for(unsigned int x = 0; x < this->size; x++) {
					if(this->map[y][x] == this->repaired)
						output << "x";
					else
						output << this->map[y][x];
					if(x != this->size - 1)
						output << " ";
				}
				output << std::endl;
			}
		}

		void repair() {
			while(this->performBestPossibleRepair()) {}
		}

	private:
		unsigned int size;
		int** map;
		static const int repaired = 10;

		enum StreetType {ROW = 0, COLUMN};
		typedef std::pair<StreetType, unsigned int> StreetRepair;

		std::list<StreetRepair> repairLog;

		bool performBestPossibleRepair() {
			StreetRepair repair;
			int repairEfficiency = 0;

			for(unsigned int x = 0; x < this->size; x++) {
				const int efficiency = this->countHolesInColumn(x);
				if(repairEfficiency < efficiency) {
					repair.first = COLUMN;
					repair.second = x;
					repairEfficiency = efficiency;
				}
			}

			for(unsigned int y = 0; y < this->size; y++) {
				const int efficiency = this->countHolesInRow(y);
				if(repairEfficiency < efficiency) {
					repair.first = ROW;
					repair.second = y;
					repairEfficiency = efficiency;
				}
			}
			
			if(repairEfficiency == 0)
				return false;

			if(repair.first == ROW)
				this->repairRow(repair.second);
			else
				this->repairColumn(repair.second);
			return true;
		}

		int countHolesInColumn(int x) {
			int count = 0;
			for(unsigned int y = 0; y < this->size; y++)
				if(this->map[y][x] <= 0)
					count++;
			return count;
		}
		int countHolesInRow(int y) {
			int count = 0;
			for(unsigned int x = 0; x < this->size; x++)
				if(this->map[y][x] <= 0)
					count++;
			return count;
		}

		void repairColumn(int x) {
			for(unsigned int y = 0; y < this->size; y++)
				this->map[y][x] = this->repaired;
			this->repairLog.push_back(std::make_pair(COLUMN, x));
		}
		void repairRow(int y) {
			for(unsigned int x = 0; x < this->size; x++)
				this->map[y][x] = this->repaired;
			this->repairLog.push_back(std::make_pair(ROW, y));
		}
};

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read matrix city file" << std::endl;
		return 1;
	}

	MatrixCity city(input);

	city.repair();

	city.printRepairLog(std::cout);
	std::cout << std::endl;
	city.printMap(std::cout);
}