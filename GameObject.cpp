#include "GameObject.h"


GameObject::GameObject() : parent { nullptr }, position { 0, 0 } {
	
}

GameObject::~GameObject() {

}

Position GameObject::getPosition() const {
	return position;
}

Position GameObject::getAbsolutePosition() const {
	if(parent == nullptr) {
		return position;
	}

	return parent->getAbsolutePosition() + position;
}


GameObject& GameObject::getParent() {
	return *parent;
}

void GameObject::setParent(GameObject& parent) {
	this->parent = &parent;
}