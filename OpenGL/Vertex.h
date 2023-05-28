#ifndef VERTEX_H
#define VERTEX_H

#include<cglm/mat3.h>
#include<cglm/vec3.h>
#include<cglm/vec2.h>

struct Vertex
{
	vec3 position;
	vec2 textureCoord;
	vec3 normal;
};

#endif // !VERTEX_H
