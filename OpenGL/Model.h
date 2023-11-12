#ifndef MODEL_H
#define MODEL_H

#include<GL/glew.h>
#include"Mesh.h"
#include"Texture.h"

struct Model
{
	GLuint VBO, VAO, EBO;//verts
	GLuint vertShader, fragShader;//shaders
	GLuint shaderProgram;//shader program
	GLuint uniformModel;
	GLuint uniformPerspective;
	GLuint uniformView;
	mat4 view;
	mat4 rotate;
	mat4 perspective;
	struct Mesh mesh;
	struct Texture texture;
};

#endif // !MODEL_H
