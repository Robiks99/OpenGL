#include"LoadVertShader.h"

ReturnType LoadVertShader(struct Model* a_Mesh, const char* a_VertShader)
{
	a_Mesh->vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(a_Mesh->vertShader, 1, &a_VertShader, NULL);
	glCompileShader(a_Mesh->vertShader);

	return E_OK;
}