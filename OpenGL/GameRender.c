#include"GameRender.h"

ReturnType GameRender(struct Database* a_database)
{
	// Clear window
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(a_database->system.window.window);

	return E_OK;
}