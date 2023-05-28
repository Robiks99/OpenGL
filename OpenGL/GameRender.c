#include"GameRender.h"
#include"UseTexture.h"
ReturnType GameRender(struct Database* a_database)
{
	// Clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	UseTexture(a_database->models[0].texture.textureID);
	RenderMesh(&a_database->models[0]);

	glfwSwapBuffers(a_database->system.window.window);

	return E_OK;
}