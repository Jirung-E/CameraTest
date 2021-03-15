#pragma once

#include "GameObject.h"
#include "Sprite.h"


class GameObject2D : public GameObject {
protected:
	Sprite sprite;

	void sync();

public:
	GameObject2D(Sprite sprite, Position position = { 0, 0 });
	GameObject2D(const std::string& sprite = NULL, Position position = { 0, 0 });
	GameObject2D(GameObject& parent, Sprite sprite, Position position = { 0, 0 });
	GameObject2D(GameObject& parent, const std::string& file = NULL, Position position = { 0, 0 });
	~GameObject2D();

	void show() const;
	void hide() const;

	void move(char direc);


	friend class Camera;
};