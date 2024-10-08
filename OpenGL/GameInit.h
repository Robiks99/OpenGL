#ifndef GAMEINIT_H
#define GAMEINIT_H

#include"Database.h"
#include"ReturnType.h"
#include"LoadMesh.h"
#include"LoadVertShader.h"
#include"LoadFragShader.h"
#include"CreateShaderProgram.h"
#include"ReadTextFile.h"
#include"LoadMeshFromFile.h"
#include"Mesh.h"
#include"LoadTextureFromFile.h"

ReturnType GameInit(struct Database* a_database);

#endif // !GAMEINIT_H
