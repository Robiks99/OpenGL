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
	
	glEnable(GL_DEPTH_TEST);

	struct Player player = a_database->gameLoopDatabase.entities.player;

	struct Mesh mesh = {0};
	player.model.mesh.vertices = LoadMeshFromFile("C:/Users/Robert/Desktop/monke.obj", &player.model);
	

	LoadMesh(Triangle,sizeof(Triangle), &player.model);
	LoadVertShader(&player.model, vertShader);
	LoadFragShader(&player.model, fragShader);
	CreateShaderProgram(&player.model);
	player.model.uniformModel = glGetUniformLocation(player.model.shaderProgram, "model");
	player.model.uniformPerspective = glGetUniformLocation(player.model.shaderProgram, "perspective");
	player.model.uniformView = glGetUniformLocation(player.model.shaderProgram, "view");


	a_database->gameLoopDatabase.entities.player = player;

	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

	// Set the framebuffer size callback
	glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

	return E_OK;
}