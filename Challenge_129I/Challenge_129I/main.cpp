/**
 * Solution for the /r/dailyprogrammer/ challenge #129I (http://reddit.com/1hzq9y/)
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

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

float vectorLength(std::vector<float>& vector) {
	float squaredLength = 0;
	for(std::vector<float>::iterator it = vector.begin(); it != vector.end(); it++)
		squaredLength += (*it) * (*it);
	return sqrt(squaredLength);
}

std::vector<float> vectorNormalize(std::vector<float> vector) {
	float length = vectorLength(vector);
	for(std::vector<float>::iterator it = vector.begin(); it != vector.end(); it++)
		*it /= length;
	return vector;
}

float vectorDotProduct(std::vector<float> vector1, std::vector<float> vector2) {
	// vector1.size() must be equal to vector2.size()
	float dotProduct = 0;
	for(int i = 0, vectorDimensions = vector1.size(); i < vectorDimensions; i++)
		dotProduct += vector1[i] * vector2[i];
	return dotProduct;
}

void printVector(std::ostream& output, std::vector<float>& vector) {
	for(std::vector<float>::iterator it = vector.begin(); it != vector.end(); it++)
		output << (it != vector.begin() ? " " : "") << (*it);
}

void readVectors(std::istream& input, std::vector<std::vector<float>>& vectors) {
	int vectorsTotal;
	input >> vectorsTotal;
	for(int i = 0; i < vectorsTotal; i++) {
		std::vector<float> vector;
		int vectorDimensions;
		input >> vectorDimensions;
		for(int j = 0; j < vectorDimensions; j++) {
			float vectorComponent;
			input >> vectorComponent;
			vector.push_back(vectorComponent);
		}
		vectors.push_back(vector);
	}
}

void processCommands(std::istream& input, std::ostream& output,
					 std::vector<std::vector<float>>& vectors) {
	 int commandsTotal;
	 input >> commandsTotal;
	 for(int i = 0; i < commandsTotal; i++) {
		char function;
		input >> function;
		int vectorIndex, vector2Index;
		std::vector<float> normalizedVector;
		switch(function) {
			case 'l':
				input >> vectorIndex;
				output << vectorLength(vectors[vectorIndex]) << std::endl;
				break;
			case 'n':
				input >> vectorIndex;
				normalizedVector = vectorNormalize(vectors[vectorIndex]);
				printVector(output, normalizedVector);
				output << std::endl;
				break;
			case 'd':
				input >> vectorIndex >> vector2Index;
				output << vectorDotProduct(vectors[vectorIndex], vectors[vector2Index])
				       << std::endl;
				break;
		}
	 }
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read vectors file" << std::endl;
		return 1;
	}
	
	std::vector<std::vector<float>> vectors;
	readVectors(input, vectors);

	processCommands(input, std::cout, vectors);
}