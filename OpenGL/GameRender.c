#include"GameRender.h"

ReturnType GameRender(struct Database* a_database)
{
	// Clear window
	glClear(GL_COLOR_BUFFER_BIT);

	RenderMesh(a_database->gameLoopDatabase.entities.player.model);

	glfwSwapBuffers(a_database->system.window.window);


	return E_OK;
}