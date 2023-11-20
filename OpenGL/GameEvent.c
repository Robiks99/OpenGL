#include"GameEvent.h"

ReturnType GameEvent(struct Database* a_database)
{
	ReturnType returnType = E_NOT_OK;

	InputManager(a_database);

	glfwPollEvents();

	return returnType;
}