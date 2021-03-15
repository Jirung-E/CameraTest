#pragma once

#include "GameObject.h"
#include "Camera.h"


namespace GameManager {
	bool CollisionCheck(GameObject& gameobject);
	void PrintCameraView(Camera& camera);



	void Play();
}