#include"LoadTextureFromFile.h"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"
ReturnType LoadTextureFromFile(struct Texture* a_Texture, const char* a_Path)
{
	if (!a_Texture)
	{
		printf("NULL pointer");
		return E_NOT_OK;
	}

	unsigned char* textureFile = stbi_load(a_Path, &a_Texture->width, &a_Texture->height, &a_Texture->bitDepth, 0);
	if (!textureFile)
	{
		printf("Failed to find: %s\n", a_Path);
		return E_NOT_OK;
	}

	glGenTextures(1, &a_Texture->textureID);
	glBindTexture(GL_TEXTURE_2D, a_Texture->textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, a_Texture->width, a_Texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureFile);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(textureFile);

	return E_OK;
}