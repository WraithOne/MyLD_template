#pragma once
#include <3rdParty.h>

class Window
{
public:
	Window();
	~Window();

private:
	//Screen dimension constants
	int SCREEN_WIDTH = 1080;
	int SCREEN_HEIGHT = 720;
	unsigned TARGETFPS = 60;
	char* WINDOWTITLE = "MyLD_template";
	int MAXFRAMESKIP = 5;
};
