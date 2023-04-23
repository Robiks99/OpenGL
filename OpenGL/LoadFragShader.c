#include"LoadFragShader.h"

ReturnType LoadFragShader(struct Model* a_Mesh, const char* a_FragShader)
{
	a_Mesh->fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(a_Mesh->fragShader, 1, &a_FragShader, NULL);
	glCompileShader(a_Mesh->fragShader);

	return E_OK;
}