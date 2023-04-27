#ifndef MODEL_H
#define MODEL_H

#include<GL/glew.h>
#include"Mesh.h"

struct Model
{
	GLuint VBO, VAO, EBO;//verts
	GLuint vertShader, fragShader;//shaders
	GLuint shaderProgram;//shader program
	GLuint uniformModel;
	unsigned vertexCount;
	struct Mesh mesh;
};

#endif // !MODEL_H
