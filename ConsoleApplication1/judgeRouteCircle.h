#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Coordinate {
	int x;
	int y;
	Coordinate() : x(0), y(0) {};
	Coordinate(int x1, int y1) : x(x1), y(y1) {};
	inline Coordinate operator + (const Coordinate &two) const {
		int tempX = x + two.x;
		int tempY = y + two.y;
		return Coordinate(tempX, tempY);
	};
	inline bool operator == (const Coordinate &two) const {
		return x == two.x && y == two.y;
	};
};

class judgeRouteCircle {
public:
	/*
	Given a sequence of moves, judge if a robot makes a circle; meaning 
	  does it move back to its original place.

	@param	moves - the string that holds the moves of the robot
	@return true if the robot ends up back at (0, 0), false otherwise
	*/
	bool judgeCircle(string moves) {

		Coordinate coordinates(0, 0);
		setup();

		for (char curr : moves)
			updateCoordinates(coordinates, curr);

		return coordinates == Coordinate(0, 0);

	};

private:
	inline void setup() {
		addingValues['R'] = Coordinate(1, 0);
		addingValues['L'] = Coordinate(-1, 0);
		addingValues['D'] = Coordinate(0, -1);
		addingValues['U'] = Coordinate(0, 1);
	};

	/*
	Updates the x,y position according to the direction given.

	@param  Coordinate coordinates - the variable that hold
			the current position that will be updated.
	@param  char direction - the move that will update coordinates.
	*/
	inline void updateCoordinates(Coordinate &coordinates, char direction) {
		coordinates = coordinates + addingValues.at(direction);
	};

	unordered_map<char, Coordinate> addingValues;

};