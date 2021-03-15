#include "Sprite.h"

#include <fstream>
#include <iostream>
#include <Windows.h>


Sprite::Sprite() : parent { nullptr }, position { 0, 0 }, pivot { 0, 0 }, width { 0 }, height { 0 } {
	sprite = new char*[1];
	sprite[0] = new char[1];
	sprite[0][0] = ' ';

	init();
}

Sprite::Sprite(const std::string& file, Position position, Position pivot) : 
	parent { nullptr }, pivot { pivot }, position { position } {
	using namespace std;

	ifstream ifile;
	ifile.open(file);
	if(ifile.is_open()) {
		ifile >> width >> height;
		string str;
		getline(ifile, str);

		sprite = new char* [height];
		for(int i=0; i<height; ++i) {
			sprite[i] = new char[width];

			string tempstr;
			getline(ifile, tempstr);

			for(int k=0; k<width; ++k) {
				sprite[i][k] = tempstr[k];
			}
		}
	}
	else {
		width = 0;
		height = 0;

		sprite = new char* [1];
		sprite[0] = new char[1];
		sprite[0][0] = ' ';
	}
	ifile.close();

	init();
}

Sprite::Sprite(GameObject& parent, const std::string& file, Position position, Position pivot) :
	Sprite { file, position, pivot } {
	this->parent = &parent;
}

Sprite::Sprite(GameObject& parent, const Sprite& sprite) : Sprite { sprite } {
	this->parent = &parent;
}

Sprite::~Sprite() {
	for(int i=0; i<height; ++i) {
		delete[] sprite[i];
	}

	delete[] sprite;
}
// -----------------------------------------------------------------------------------------------


void Sprite::init() {
	left = -static_cast<int>((width-1)/2);
	right = static_cast<int>(width/2);
	top = -static_cast<int>((height-1)/2);
	bottom = static_cast<int>(height/2);
}

bool Sprite::moveBrush(Position pos) const {
	if(pos.x < 0 || pos.y < 0) {
		return false;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { SHORT(pos.x), SHORT(pos.y) });

	return true;
}


void Sprite::show() const {
	using namespace std;

	int parent_x = 0;
	int parent_y = 0;

	if(parent != nullptr) {
		parent_x = parent->getAbsolutePosition().x;
		parent_y = parent->getAbsolutePosition().y;
	}

	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			if(moveBrush(Position { parent_x + position.x + left + k, parent_y + position.y + top + i }) == true) {
				if(sprite[i][k] != ' ') {
					cout << sprite[i][k];
				}
			}
		}
	}
}

void Sprite::hide() const {
	using namespace std;

	int parent_x = 0;
	int parent_y = 0;

	if(parent != nullptr) {
		parent_x = parent->getAbsolutePosition().x;
		parent_y = parent->getAbsolutePosition().y;
	}

	for(int i=0; i<height; ++i) {
		for(int k=0; k<width; ++k) {
			if(moveBrush(Position { parent_x + position.x + left + k, parent_y + position.y + top + i }) == true) {
				if(sprite[i][k] != ' ') {
					cout << ' ';
				}
			}
		}
	}
}



Position Sprite::getPosition() const {
	return position;
}

Position Sprite::getAbsolutePosition() const {
	if(parent == nullptr) {
		return position;
	}

	return parent->getAbsolutePosition() + position;
}

void Sprite::setPosition(Position pos) {
	this->position = pos;
}


const GameObject& Sprite::getParent() {
	return *parent;
}

void Sprite::setParent(GameObject& parent) {
	this->parent = &parent;
}

void Sprite::update() {
	hide();
	show();
}