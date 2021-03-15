#pragma once

#include "Position.h"


class GameObject {
protected:
	GameObject* parent;
	Position position;

public:
	GameObject();
	virtual ~GameObject() = 0;

	Position getPosition() const;
	Position getAbsolutePosition() const;

	GameObject& getParent();
	void setParent(GameObject& parent);
};