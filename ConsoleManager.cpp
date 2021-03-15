#include "ConsoleManager.h"


void ConsoleManager::SetConsoleView() {
	system("mode con:cols=150 lines=30");
}

void ConsoleManager::SetConsoleFullScreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void ConsoleManager::GotoXY(SHORT x, SHORT y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { x, y });
}


void ConsoleManager::SetViewers() {
	using namespace std;

	GotoXY(1+3, 1);
	cout << "View";

	GotoXY(1+1, 2);
	for(int i=1+2; i<width/2; ++i) {
		cout << '-';
	}
	for(int i=1+2; i<height-2; ++i) {
		GotoXY(1, i);
		cout << '|';
		GotoXY(width/2-1, i);
		cout << '|';
	}
	GotoXY(1+1, height-2);
	for(int i=1+2; i<width/2; ++i) {
		cout << '-';
	}


	GotoXY(width/2+3, 1);
	cout << "Camera";

	GotoXY(width/2+1, 2);
	for(int i=1+2; i<width/2; ++i) {
		cout << '-';
	}
	for(int i=1+2; i<height-2; ++i) {
		GotoXY(width/2, i);
		cout << '|';
		GotoXY(width-2, i);
		cout << '|';
	}
	GotoXY(width/2+1, height-2);
	for(int i=1+2; i<width/2; ++i) {
		cout << '-';
	}
}