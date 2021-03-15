#include "Camera.h"


Camera::Camera() : target_world { nullptr }, target_object { nullptr }, position { 0, 0 }, width { 51 }, height { 16 } {
	picture = new char* [height];
	for(int i=0; i<height; ++i) {
		picture[i] = new char[width];
	}
}

Camera::Camera(GameObject2D& parent) : Camera { } {
	this->target_object = &parent;
}

Camera::Camera(World& target) : Camera { } {
	this->target_world = &target;
}

Camera::Camera(World& target, GameObject2D& parent) : Camera { } {
	this->target_world = &target;
	this->target_object = &parent;
}

Camera::~Camera() {
	for(int i=0; i<height; ++i) {
		delete[] picture[i];
	}
	delete[] picture;
}



void Camera::setPosition(int x, int y) {
	position = { x, y };
}

void Camera::setPosition(Position position) {
	this->position = position;
}


void Camera::update() {
	if(target_object == nullptr) {
		return;
	}
}


void Camera::setTargetWorld(World& world) {
	this->target_world = &world;
}

World& Camera::getTargetWorld() {
	return *target_world;
}


void Camera::takePicture() {
	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			picture[i][k] = ' ';
		}
	}

	if(target_world == nullptr) {
		return;
	}

	// 배경 출력
	for(int i=0; i<target_world->background.height; ++i) {			// 장면 갱신을 위해 빈 부분도 출력
		for(int k=0; k<target_world->background.width; ++k) {
			int dx = target_object->sprite.getAbsolutePosition().x - (target_world->background.getAbsolutePosition().x + target_world->background.left + k);
			int dy = target_object->sprite.getAbsolutePosition().y - (target_world->background.getAbsolutePosition().y + target_world->background.top + i);
			
			dx *= -1;
			dy *= -1;

			if(dx >= width/2 || dx < -width/2) continue;
			if(dy >= height/2 || dy < -height/2) continue;

			picture[height/2+dy][width/2+dx] = target_world->background.sprite[i][k];
		}
	}

	// 플레이어 출력
	for(int i=0; i<target_object->sprite.height; ++i) {				// 덮어씌우는 형태이므로 빈 부분 출력 안함
		for(int k=0; k<target_object->sprite.width; ++k) {
			if(target_object->sprite.sprite[i][k] == ' ') {
				continue;
			}

			int dx = target_object->sprite.left + k;
			int dy = target_object->sprite.top + i;

			if(dx >= width/2 || dx < -width/2) continue;
			if(dy >= height/2 || dy < -height/2) continue;

			picture[height/2+dy][width/2+dx] = target_object->sprite.sprite[i][k];
		}
	}

	//int i = target_world->objects.size();
}

char** Camera::getPicture() const {
	return picture;
}

int Camera::getWidth() const {
	return width;
}

int Camera::getHeight() const {
	return height;
}

//void Camera::printPictureTo(int x, int y) {
//	if(parent == nullptr) {
//		return;
//	}
//
//
//	parent->getAbsolutePosition() + position;
//}