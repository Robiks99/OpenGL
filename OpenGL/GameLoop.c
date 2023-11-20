#include"GameLoop.h"

ReturnType GameLoop(struct Database* a_database)
{
	ReturnType returnType = E_NOT_OK;

	returnType = GameInit(a_database);
	if (returnType != E_OK)
	{
		printf("Error: GameInit failed\n");
	}
	else
	{
		float previousTime = 0.0f;
		float currentTime = 0.0f;
		while (a_database->system.appState == Game)
		{
			currentTime = glfwGetTime();
			a_database->system.deltaTime = currentTime - previousTime;
			previousTime = currentTime;
			GameEvent(a_database);
			GameUpdate(a_database);
			GameRender(a_database);
			updateFPS(a_database->system.window.window);

		}

	}
	

	return returnType;
}