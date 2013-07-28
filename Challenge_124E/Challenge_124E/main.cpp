/**
 * Solution for the /r/dailyprogrammer/ challenge #124E (http://reddit.com/1dsyrk/)
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

struct Edge {
	char id;
	std::pair<int, int> points;
};

bool compareEdgesByLowestPoints(Edge& edge1, Edge& edge2) {
	int edge1Low = std::min(edge1.points.first, edge1.points.second);
	int edge2Low = std::min(edge2.points.first, edge2.points.second);
	return edge1Low < edge2Low;
}

void readEdges(std::istream& stream, std::list<Edge>& edges) {
	int totalEdges;
	stream >> totalEdges;

	for(int i = 0; i < totalEdges; i++) {
		Edge edge;
		stream >> edge.id >> edge.points.first >> edge.points.second;
		edges.push_back(edge);
	}
}

void printEdgeIdentifiers(std::ostream& output, std::list<Edge>& edges) {
	for(std::list<Edge>::iterator it = edges.begin(); it != edges.end(); it++)
		output << it->id << " ";
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read graph file" << std::endl;
		return 1;
	}

	std::list<Edge> edges;
	readEdges(input, edges);
	
	edges.sort(compareEdgesByLowestPoints);

	printEdgeIdentifiers(std::cout, edges);
	std::cout << std::endl;
}