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
	struct Model *models = a_database->models;
	struct Mesh mesh = {0};

	LoadMeshFromFile("C:/Users/Robert/Desktop/triangle.obj", &models[0]);
	LoadTextureFromFile(&models[0].texture, "C:/Users/Robert/Desktop/test.png");

	LoadMesh(&models[0]);
	LoadVertShader(&models[0], vertShader);
	LoadFragShader(&models[0], fragShader);
	CreateShaderProgram(&models[0]);
	models[0].uniformModel = glGetUniformLocation(models[0].shaderProgram, "model");
	models[0].uniformPerspective = glGetUniformLocation(models[0].shaderProgram, "perspective");
	models[0].uniformView = glGetUniformLocation(models[0].shaderProgram, "view");

	a_database->gameLoopDatabase.entities.player = player;

	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

	// Set the framebuffer size callback
	glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

	return E_OK;
}