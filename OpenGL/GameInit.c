#include"GameInit.h"

GLfloat Triangle[] =
{
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

ReturnType GameInit(struct Database* a_database)
{
	char* vertShader = ReadTextFile("DefaultShader.vert");
	char* fragShader = ReadTextFile("DefaultShader.frag");
	
	struct Player player = a_database->gameLoopDatabase.entities.player;

	LoadMesh(Triangle,sizeof(Triangle), &player.mesh);
	LoadVertShader(&player.mesh, vertShader);
	LoadFragShader(&player.mesh, fragShader);
	CreateShaderProgram(&player.mesh);

	a_database->gameLoopDatabase.entities.player = player;

	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

		// Set the framebuffer size callback
		//glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

	return E_OK;
}