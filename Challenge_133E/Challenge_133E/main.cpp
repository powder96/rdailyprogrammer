/**
 * Solution for the /r/dailyprogrammer/ challenge #133E (http://reddit.com/1iambu/)
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

static const int visitorsMax = 1024;
static const int roomsMax = 100;

struct RoomStatistics {
	int averageVisitTime;
	int totalVisits;
	RoomStatistics(): averageVisitTime(0), totalVisits(0) {}
};

void parseLogAndGenerateStatistics(std::istream& stream, RoomStatistics rooms[]) {
	int totalEvents;
	stream >> totalEvents;

	int visitorLocationTimestamp[visitorsMax];

	for(int i = 0; i < totalEvents; i++) {
		int visitorId, roomId, timestamp;
		char type;
		stream >> visitorId >> roomId >> type >> timestamp;
		if(type == 'I')
			visitorLocationTimestamp[visitorId] = timestamp;
		else {
			const int visitDuration = timestamp - visitorLocationTimestamp[visitorId];
			visitorLocationTimestamp[visitorId] = 0;
			
			rooms[roomId].averageVisitTime += visitDuration;
			if(rooms[roomId].totalVisits > 0)
				rooms[roomId].averageVisitTime /= 2;
			rooms[roomId].totalVisits += 1;
		}
	}
}

void printStatistics(std::ostream& stream, RoomStatistics rooms[]) {
	for(int i = 0; i < roomsMax; i++)
		if(rooms[i].totalVisits > 0)
			stream << "Room " << i << ", "
			       << rooms[i].averageVisitTime << " minute average visit, "
			       << rooms[i].totalVisits << " visitor"
				           << (rooms[i].totalVisits != 1 ? "s" : "") << " total"
			       << std::endl;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read traffic log" << std::endl;
		return 1;
	}

	RoomStatistics rooms[roomsMax];
	parseLogAndGenerateStatistics(input, rooms);

	printStatistics(std::cout, rooms);
}