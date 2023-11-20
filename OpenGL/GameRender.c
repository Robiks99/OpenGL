#include"GameRender.h"
#include"UseTexture.h"
ReturnType GameRender(struct Database* a_database)
{
	// Clear window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	UseTexture(a_database->gameLoopDatabase.entities.player.entity.model.texture.textureID);
	RenderMesh(&a_database->gameLoopDatabase.entities.player.entity, a_database->system.window);

	glfwSwapBuffers(a_database->system.window.window);

	return E_OK;
}