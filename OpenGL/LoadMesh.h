#ifndef LOADMESH_H
#define LOADMESH_H

//#include<GL/glew.h>
#include"ReturnType.h"
#include"Mesh.h"

ReturnType LoadMesh(GLfloat a_Vertices[], int a_VerticesAmount, struct Mesh* a_Mesh);

#endif // !LOADMESH_H
