#ifndef POLYGON_H
#define POLYGON_H

#include<cglm/mat3.h>
#include<cglm/vec3.h>
#include<cglm/vec2.h>

struct Polygon
{
	mat3 vectors;
	vec3 normal;
	vec2 textureCoord;
};

#endif // !POLYGON_H
