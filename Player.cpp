#include "Player.h"


Player::Player(GameObject& parent, Sprite sprite, Position position) : GameObject2D { parent, sprite, position } {

}

Player::Player(GameObject& parent, const std::string & sprite, Position position) : GameObject2D { parent, sprite, position } {

}

Player::Player(Sprite sprite, Position position) : GameObject2D { sprite, position } {
	
}

Player::Player(const std::string& sprite, Position position) : GameObject2D { sprite, position } {
	
}

Player::~Player() {

}
// -----------------------------------------------------------------------------