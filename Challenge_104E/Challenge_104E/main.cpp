/**
 * Solution for the /r/dailyprogrammer/ challenge #104E (http://reddit.com/11paok/, http:://reddit.com/11pal7/)
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

unsigned int redmondPowerPlantOperationalDays(unsigned int daysToSimulate) {
	unsigned int operationalDays = daysToSimulate;
	operationalDays -= daysToSimulate / 3; // offline b/c of local demands
	operationalDays -= daysToSimulate / 14; // offline b/c of refueling
	operationalDays -= daysToSimulate / 100; // offline b/c of maintenance
	operationalDays += daysToSimulate / (3 * 14); // offline b/c of both demands and refueling 
	operationalDays += daysToSimulate / (14 * 100); // offline b/c of both refueling and maintenance
	operationalDays += daysToSimulate / (3 * 100); // offline b/c of both demands and maintenance
	operationalDays -= daysToSimulate / (3 * 14 * 100); // offline b/c of demands, refueling, and maintenance
	return operationalDays;
}

int main() {
	std::cout << "Redmond powerplant will be operational for " << redmondPowerPlantOperationalDays(10) << " days." << std::endl;
}