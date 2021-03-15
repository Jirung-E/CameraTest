#include "World.h"


World::World(Sprite& background) : background { background } {

}

World::World(const std::string& background) : background { background } {

}



void World::insert(GameObject2D& gameobject) {
	objects.push_back(&gameobject);
}


void World::setBackground(Sprite& sprite) {
	background = sprite;
}

void World::setBackground(const std::string& file) {
	background = Sprite { file };
}

void World::showBackground(int x, int y) {
	background.setPosition({ x, y });
	background.show();
}


GameObject2D* World::getObject(unsigned int n) {
	// TODO: 여기에 return 문을 삽입합니다.
	if(objects.size() < n) {
		return nullptr;
	}
	return objects[n];
}