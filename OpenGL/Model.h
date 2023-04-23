#ifndef MODEL_H
#define MODEL_H

#include<GL/glew.h>

struct Model
{
	GLuint VBO, VAO;//verts
	GLuint vertShader, fragShader;//shaders
	GLuint shaderProgram;//shader program
};

#endif // !MODEL_H
