#include"GameInit.h"

const char* vertex_shader_source =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char* fragment_shader_source =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n";

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
		struct Player player = a_database->gameLoopDatabase.entities.player;

		LoadMesh(Triangle,sizeof(Triangle), &player.mesh);
		LoadVertShader(&player.mesh, vertex_shader_source);
		LoadFragShader(&player.mesh, fragment_shader_source);
		CreateShaderProgram(&player.mesh);

		a_database->gameLoopDatabase.entities.player = player;

		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

		// Set the framebuffer size callback
		//glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

	return E_OK;
}