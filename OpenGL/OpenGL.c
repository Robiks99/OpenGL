#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <stdio.h>

#include"Database.h"
#include"GameLoop.h"
#include"ReturnType.h"

ReturnType DatabaseInit(struct Database* database)
{
	ReturnType returnType = E_NOT_OK;

	if (!glfwInit())
	{
		printf("Error Initialising GLFW");
		glfwTerminate();
	}
	else
	{
		returnType = E_OK;
	}


	return returnType;
}
ReturnType WindowInit(struct Window* a_window)
{
	struct Window window = *a_window;
	// Setup GLFW Windows Properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	window.window = glfwCreateWindow(800, 600, "Test Window", NULL, NULL);
	if (!window.window)
	{
		printf("Error creating GLFW window!");
		glfwTerminate();
	}

	// Get buffer size information
	glfwGetFramebufferSize(window.window, &window.bufferWidth, &window.bufferHeight);

	// Set the current context
	glfwMakeContextCurrent(window.window);

	// Allow modern extension access
	glewExperimental = GL_TRUE;

	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		printf("Error: %s", glewGetErrorString(error));
		glfwDestroyWindow(window.window);
		glfwTerminate();
	}

	// Create Viewport
	glViewport(0, 0, window.bufferWidth, window.bufferHeight);

	*a_window = window;
}

int main()
{
	struct Database database = {0};
	database.system.appState = Game;
	//database.gameLoopDatabase.i = 1;
	DatabaseInit(&database);
	WindowInit(&database.system.window);

	//main loop
	while (database.system.appState != Quit)
	{
		if (database.system.appState == Game)
		{
			GameLoop(&database);

		}
	}

}
