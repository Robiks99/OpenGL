#ifndef ENTITY_H
#define ENTITY_H

#include<cglm/vec3.h>
#include"Model.h"

struct Entity
{
	vec3 position, rotation;
	struct Model model;
};

#endif // !ENTITY_H
