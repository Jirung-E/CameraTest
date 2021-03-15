#pragma once

#include "GameObject.h"

#include <string>


class Sprite {
	GameObject* parent;
	char** sprite;
	Position position;
	Position pivot;

	int width;
	int height;	

	int left;
	int right;
	int top;
	int bottom;

	bool moveBrush(Position pos) const;
	void init();

public:
	Sprite();
	Sprite(const std::string& file, Position position = { 0, 0 }, Position pivot = { 0, 0 });
	Sprite(GameObject& parent, const std::string& file, Position position = { 0, 0 }, Position pivot = { 0, 0 });
	Sprite(GameObject& parent, const Sprite& sprite);
	~Sprite();


	void show() const;
	void hide() const;

	int getWidth() const;
	int getHeight() const;

	Position getPivot() const;
	void setPivot(Position pivot);

	Position getPosition() const;
	Position getAbsolutePosition() const;
	void setPosition(Position pos);

	int getLeft() const;
	int getRight() const;
	int getTop() const;
	int getBottom() const;


	const GameObject& getParent();
	void setParent(GameObject& parent);

	void update();


	friend class Camera;
};