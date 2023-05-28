#ifndef LOADTEXTUREFROMFILE_H
#define LOADTEXTUREFROMFILE_H

#include<GL/glew.h>
#include<stdio.h>
#include"ReturnType.h"
#include"Texture.h"


ReturnType LoadTextureFromFile(struct Texture* a_Texture, const char* a_Path);

#endif // !LOADTEXTUREFROMFILE_H
