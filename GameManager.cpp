#include "GameManager.h"

#include "ConsoleManager.h"
#include "World.h"
#include "Player.h"


bool GameManager::CollisionCheck(GameObject& gameobject) {
	using namespace ConsoleManager;

	if(gameobject.getAbsolutePosition().x <= view_left || gameobject.getAbsolutePosition().x >= view_right) {
		return true;
	}
	if(gameobject.getAbsolutePosition().y <= view_top || gameobject.getAbsolutePosition().y >= view_bottom) {
		return true;
	}

	return false;
}

void GameManager::PrintCameraView(Camera& camera) {
	using namespace ConsoleManager;
	using namespace std;

	for(int i=0; i<camera.getHeight(); ++i) {
		GotoXY((camera_left + camera_right) / 2 - camera.getWidth()/2, (camera_top + camera_bottom) / 2 - camera.getHeight()/2 + i);
		for(int k=0; k<camera.getWidth(); ++k) {
			cout << camera.getPicture()[i][k];			// ��� ������ ���� Sprite::show()�� �ٸ��� �� �κе� ��� �ؾ���
		}
	}
}


void GameManager::Play() {
	using namespace ConsoleManager;

	SetConsoleView();
	SetViewers();

	World world { "World.txt" };
	Player player { "Player.txt", { 5, 5 } };
	world.insert(player);

	Camera camera { world, *world.getObject(0) };

	world.showBackground(30, 15);
	player.show();
	camera.takePicture();
	PrintCameraView(camera);

	while(true) {
		if(_kbhit()) {
			char c = _getch();
			if(c == 'q' || c == 'e') {
				break;
			}
			player.hide();
			player.move(c);

			if(CollisionCheck(player)) {
				if(c == 'a') player.move('d');
				else if(c == 'd') player.move('a');
				else if(c == 'w') player.move('s');
				else if(c == 's') player.move('w');
			}
			world.showBackground(30, 15);
			player.show();
			camera.takePicture();
			PrintCameraView(camera);
		}
	}
}