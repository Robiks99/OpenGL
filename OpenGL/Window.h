#ifndef WINDOW_H
#define WINDOW_H

#include<GLFW/glfw3.h>

struct Window
{
	GLFWwindow* window;

	GLint width, height;
	GLint bufferWidth, bufferHeight;

	GLfloat lastX;
	GLfloat lastY;
	GLfloat xChange;
	GLfloat yChange;
};

#endif // !WINDOW_H
