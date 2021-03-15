#pragma once

#include "GameObject2D.h"


class Player : public GameObject2D {
	int hp;
	int hp_max;
	int mp;
	int mp_max;
	int level;
	int exp;

public:
	Player(GameObject& parent, Sprite sprite, Position position = { 0, 0 });
	Player(GameObject& parent, const std::string& sprite = NULL, Position position = { 0, 0 });
	Player(Sprite sprite, Position position = { 0, 0 });
	Player(const std::string& sprite = NULL, Position position = { 0, 0 });
	~Player();
};