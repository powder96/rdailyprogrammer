/**
 * Solution for the /r/dailyprogrammer/ challenge #130I (http://reddit.com/1ihm0q/)
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
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

struct Event {
	int visitorId;
	int roomId;
	bool isIn;
	int timestamp;
	Event(): visitorId(0), roomId(0), isIn(false), timestamp(0) {}
};

bool compareEventsByTimestamp(Event& event1, Event& event2) {
	return event1.timestamp < event2.timestamp;
}

void generateEvents(std::list<Event>& events, int eventPairs, int visitors, int rooms, int timeLow, int timeHigh) {
	std::vector<int> visitorTimeLow;
	for(int i = 0; i < visitors; i++)
		visitorTimeLow.push_back(timeLow);
	
	for(int i = 0; i < eventPairs; i++) {
		Event event;
		
		event.visitorId = rand() % visitors;
		event.roomId = rand() % rooms;
		event.isIn = true;
		const int eventTimeLow = visitorTimeLow[event.visitorId];
		const int eventTimeHigh = (int)(eventTimeLow + (timeHigh - eventTimeLow) * ((i + 1.0f) / eventPairs));
		if((eventTimeHigh - eventTimeLow) != 0)
			event.timestamp = eventTimeLow + rand() % (eventTimeHigh - eventTimeLow);
		else
			event.timestamp = eventTimeLow;
		events.push_back(event);

		event.isIn = false;
		if((eventTimeHigh - event.timestamp) != 0)
			event.timestamp = event.timestamp + rand() % (eventTimeHigh - event.timestamp);
		events.push_back(event);

		visitorTimeLow[event.visitorId] = event.timestamp;
	}

	events.sort(compareEventsByTimestamp);
}

void printEvents(std::ostream& stream, std::list<Event>& events) {
	stream << events.size() << std::endl;
	for(std::list<Event>::iterator it = events.begin(); it != events.end(); it++)
		stream << it->visitorId << " " << it->roomId << " "
		       << (it->isIn ? "I" : "O") << " " << it->timestamp << std::endl;
}

int main() {
	int eventPairs, visitors, rooms, timeLow, timeHigh;
	std::cout << "Format: \"<int:events> <int:visitors> <int:rooms> <int:timeLow> <int:timeHigh>\"" << std::endl;
	std::cin >> eventPairs >> visitors >> rooms >> timeLow >> timeHigh;

	std::list<Event> events;
	srand((unsigned int)time(NULL));
	generateEvents(events, eventPairs, visitors + 1, rooms + 1, timeLow, timeHigh);

	std::cout << std::endl;
	printEvents(std::cout, events);
}