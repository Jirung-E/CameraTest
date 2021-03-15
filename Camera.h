#pragma once

#include "GameObject2D.h"
#include "World.h"


class Camera {
	World* target_world;
	GameObject2D* target_object;
	Position position;
	
	int width;
	int height;
	char** picture;

public:
	Camera();
	Camera(GameObject2D& parent);
	Camera(World& target);
	Camera(World& target, GameObject2D& parent);
	~Camera();

	void setPosition(int x, int y);
	void setPosition(Position position);

	void update();

	void setTargetWorld(World& world);
	World& getTargetWorld();

	void takePicture();
	char** getPicture() const;

	int getWidth() const;
	int getHeight() const;
	//void printPictureTo(int x, int y);
};