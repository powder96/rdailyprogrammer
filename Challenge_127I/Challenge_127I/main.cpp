/**
 * Solution for the /r/dailyprogrammer/ challenge #127I (http://reddit.com/1g09qy/)
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
#include <map>

struct ForwardingRule {
	int source;
	int destination;
	int startDay;
	int activeDays;
};

void readForwardingRules(std::istream& stream, std::list<ForwardingRule>& rules) {
	int totalRules;
	stream >> totalRules;

	for(int i = 0; i < totalRules; i++) {
		ForwardingRule rule;
		stream >> rule.source >> rule.destination >> rule.startDay >> rule.activeDays;
		rules.push_back(rule);
	}
}

void filterOutInactiveForwardingRules(std::list<ForwardingRule>& rules, int day) {
	for(std::list<ForwardingRule>::iterator it = rules.begin(); it != rules.end();) {
		if(day < it->startDay || day > it->startDay + it->activeDays)
			it = rules.erase(it);
		else
			it++;
	}
}

int countChainLength(std::list<ForwardingRule>& rules, std::map<int, int>& lookup, int phoneNumber) {
	std::map<int, int>::iterator it = lookup.find(phoneNumber);
	if(it != lookup.end())
		return it->second;

	lookup[phoneNumber] = -1;

	int length = 0;
	for(std::list<ForwardingRule>::iterator it = rules.begin(); it != rules.end(); it++)
		if(it->source == phoneNumber) {
			const int subChainLength = countChainLength(rules, lookup, it->destination);
			if(subChainLength == -1) { // circular forwarding
				length = -1;
				break;
			}
			length += subChainLength + 1;
		}

	lookup[phoneNumber] = length;
	return length;
}

int countMaxChainLength(std::list<ForwardingRule>& rules) {
	int maxLength = 0;
	std::map<int, int> countChainLengthLookup;
	for(std::list<ForwardingRule>::iterator it = rules.begin(); it != rules.end(); it++) {
		const int chainLength = countChainLength(rules, countChainLengthLookup, it->source);
		if(chainLength == -1)
			return -1; // circular forwarding
		maxLength = std::max(maxLength, chainLength);
	}
	return maxLength;
}

int main(int argc, char** argv) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if(!input.good()) {
		std::cout << "Cannot read forwarding rules file" << std::endl;
		return 1;
	}

	std::list<ForwardingRule> rules;
	readForwardingRules(input, rules);

	int day;
	input >> day;
	filterOutInactiveForwardingRules(rules, day);

	std::cout << rules.size() << " call forwardings set up on day " << day << std::endl;

	int maxChainLength = countMaxChainLength(rules);
	if(maxChainLength == -1)
		std::cout << "Circular forwarding was detected on day " << day << std::endl;
	else
		std::cout << maxChainLength << " call forwardings are the longest chain on day " << day << std::endl;
}