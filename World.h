#pragma once

#include <vector>
#include <string>

#include "GameObject2D.h"
#include "Sprite.h"


class World {
	std::vector<GameObject2D*> objects;
	Sprite background;

public:
	World() = default;
	World(Sprite& background);
	World(const std::string& background);

	void insert(GameObject2D& gameobject);
	void setBackground(Sprite& sprite);
	void setBackground(const std::string& file);
	void showBackground(int x = 0, int  y = 0);

	GameObject2D* getObject(unsigned int n);


	friend class Camera;
};