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
	glfwSwapInterval(0);

	a_database->system.deltaTime = 0.0f;

	struct Player *player = &a_database->gameLoopDatabase.entities.player;
	struct Model *models = a_database->models;
	struct Mesh mesh = {0};

	LoadMeshFromFile("C:/Users/Robert/Desktop/Sheep.obj", &models[0]);
	LoadTextureFromFile(&models[0].texture, "C:/Users/Robert/Desktop/sheep.png");

	LoadMesh(&models[0]);
	LoadVertShader(&models[0], vertShader);
	LoadFragShader(&models[0], fragShader);
	CreateShaderProgram(&models[0]);
	glm_mat4_identity(models[0].rotate);
	glm_mat4_identity(models[0].perspective);
	glm_mat4_identity(models[0].view);
	player->entity.model = models[0];
	

	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

	// Set the framebuffer size callback
	glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

	return E_OK;
}