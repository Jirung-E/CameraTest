#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>


namespace ConsoleManager {
	const SHORT width = 150;
	const SHORT height = 30;
	const SHORT view_left = 2;
	const SHORT view_right = width/2-2;
	const SHORT view_top = 3;
	const SHORT view_bottom = height-3;
	const SHORT camera_left = width/2+1;
	const SHORT camera_right = width-3;
	const SHORT camera_top = 3;
	const SHORT camera_bottom = height-3;

	void SetConsoleView();
	void SetConsoleFullScreen();
	void GotoXY(SHORT x, SHORT y);

	void SetViewers();
};