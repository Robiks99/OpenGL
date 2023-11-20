#include"MoveEntity.h"

ReturnType MoveEntity(struct Entity* a_entity,vec3 move)
{
	for (size_t i = 0; i < 3; i++)
	{
		a_entity->position[i] += move[i];
	}
}