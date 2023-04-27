#include"OpenGL.h"

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

	return E_OK;
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

//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stdio.h>
//
//const char* vertex_shader_source =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\n";
//
//const char* fragment_shader_source =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"    FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
//"}\n";
//
//float vertices[] = {
//    -0.5f, -0.5f, 0.0f,
//    0.5f, -0.5f, 0.0f,
//    0.0f, 0.5f, 0.0f
//};
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//int main(int argc, char** argv)
//{
//    // Initialize GLFW
//    if (!glfwInit()) {
//        return -1;
//    }
//
//    // Create a window and context
//    GLFWwindow* window = glfwCreateWindow(640, 480, "Triangle", NULL, NULL);
//    if (!window) {
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // Initialize GLEW
//    GLenum err = glewInit();
//    if (err != GLEW_OK) {
//        return -1;
//    }
//
//    // Create vertex buffer object and vertex array object
//    GLuint VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    // Bind vertex array object and vertex buffer object
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//    // Copy vertex data to buffer
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // Set vertex attribute pointers
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Create shader program
//    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
//    glCompileShader(vertex_shader);
//
//    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
//    glCompileShader(fragment_shader);
//
//    GLuint shader_program = glCreateProgram();
//    glAttachShader(shader_program, vertex_shader);
//    glAttachShader(shader_program, fragment_shader);
//    glLinkProgram(shader_program);
//
//    // Delete shader objects
//    glDeleteShader(vertex_shader);
//    glDeleteShader(fragment_shader);
//
//    // Set the clear color and viewport
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glViewport(0, 0, 640, 480);
//
//    // Set the framebuffer size callback
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // Enter the main loop
//    while (!glfwWindowShouldClose(window)) {
//        // Clear the color buffer
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // Use shader program
//        glUseProgram(shader_program);
//
//        // Bind vertex array object
//        glBindVertexArray(VAO);
//
//        // Draw the triangle
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        // Swap buffers and poll events
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Delete vertex buffer and vertex array objects
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//    // Terminate GLFW
//    glfwTerminate();
//
//    return 0;
//}