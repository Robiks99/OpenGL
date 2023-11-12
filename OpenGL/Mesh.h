#ifndef MESH_H
#define MESH_H

#include"Vertex.h"

struct Mesh
{
	struct Vertex* vertices;
	unsigned int* indices;
	int vAmount, vtAmount, vnAmount, verticesCount;
	int fAmount;
};

#endif // !MESH_H
