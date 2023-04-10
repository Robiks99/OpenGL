#ifndef MESH_H
#define MESH_H

#include<GL/glew.h>

struct Mesh
{
	GLuint VBO, VAO;//verts
	GLuint vertShader, fragShader;//shaders
	GLuint shaderProgram;//shader program
};

#endif // !MESH_H
