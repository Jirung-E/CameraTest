#pragma once

class Position {
public:
	int x;
	int y;

	Position operator+(Position position);
};