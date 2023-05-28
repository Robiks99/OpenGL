#include"UseTexture.h"

ReturnType UseTexture(const GLuint a_TextureID)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, a_TextureID);
	return E_OK;
}