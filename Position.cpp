#include "Position.h"

Position Position::operator+(Position position) {
	return { x + position.x, y + position.y };
}