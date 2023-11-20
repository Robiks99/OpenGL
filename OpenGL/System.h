#ifndef SYSTEM_H
#define SYSTEM_H

#include"AppState.h"
#include"Window.h"
#include"Camera.h"

struct System
{

	AppState appState;
	struct Camera camera;
	struct Window window;
	float deltaTime;
};

#endif // !SYSTEM_H
