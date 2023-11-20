#include"InputManager.h"
#include<stdio.h>

void PlayerMovement(struct Database* a_database)
{
	float deltaTime = a_database->system.deltaTime;

	if (glfwGetKey(a_database->system.window.window, GLFW_KEY_W))
	{
		printf("W\n");
		a_database->gameLoopDatabase.entities.player.entity.position[2] -= 0.1f * deltaTime * 80;
	}
	if (glfwGetKey(a_database->system.window.window, GLFW_KEY_S))
	{
		printf("S\n");
		a_database->gameLoopDatabase.entities.player.entity.position[2] += 0.1f * deltaTime * 80;
	}
	if (glfwGetKey(a_database->system.window.window, GLFW_KEY_A))
	{
		printf("A\n");
		a_database->gameLoopDatabase.entities.player.entity.position[0] -= 0.1f * deltaTime * 80;
	}
	if (glfwGetKey(a_database->system.window.window, GLFW_KEY_D))
	{
		printf("D\n");
		a_database->gameLoopDatabase.entities.player.entity.position[0] += 0.1f * deltaTime * 80;
	}if (glfwGetKey(a_database->system.window.window, GLFW_KEY_Q))
	{
		printf("Q\n");
		a_database->gameLoopDatabase.entities.player.entity.rotation[1] -= 0.4f * deltaTime * 80;
	}
	if (glfwGetKey(a_database->system.window.window, GLFW_KEY_E))
	{
		printf("E\n");
		a_database->gameLoopDatabase.entities.player.entity.rotation[1] += 0.4f * deltaTime * 80;
	}
}

ReturnType InputManager(struct Database* a_database)
{
	PlayerMovement(a_database);
}

