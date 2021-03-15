#include "GameObject2D.h"


GameObject2D::GameObject2D(Sprite sprite, Position position) : sprite { sprite } {
	this->parent = nullptr;
	this->position = position;
}

GameObject2D::GameObject2D(const std::string& sprite, Position position) : sprite { *this, sprite } {
	this->parent = nullptr;
	this->position = position;
}

GameObject2D::GameObject2D(GameObject& parent, Sprite sprite, Position position) : GameObject2D { sprite, position } {
	this->parent = &parent;
}

GameObject2D::GameObject2D(GameObject& parent, const std::string & file, Position position) : GameObject2D { file, position } {
	this->parent = &parent;
}

GameObject2D::~GameObject2D() {
	
}
// -----------------------------------------------------------------------------


void GameObject2D::sync() {
	sprite.update();
}


void GameObject2D::show() const {
	sprite.show();
}

void GameObject2D::hide() const {
	sprite.hide();
}


void GameObject2D::move(char direc) {
	switch(direc) {
		case 'w':
			//hide();
			position.y--;
			break;
		case 'a':
			//hide();
			position.x--;
			break;
		case 's':
			//hide();
			position.y++;
			break;
		case 'd':
			//hide();
			position.x++;
			break;
		default:
			return;
	}

	//sync();

	//show();
}