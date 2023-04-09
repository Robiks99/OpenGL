#include"GameLoop.h"
#include"GameInit.h"
#include"GameEvent.h"
#include"GameUpdate.h"
#include"GameRender.h"

#include<stdio.h>

void GameLoop(struct Database* a_database)
{
	ReturnType returnType = E_NOT_OK;

	returnType = GameInit(a_database);
	if (returnType != E_OK)
	{
		printf("Error: GameInit failed");
	}
	else
	{
		while (a_database->system.appState == Game)
		{
			GameEvent(a_database);
			GameUpdate(a_database);
			GameRender(a_database);

		}
	}
	

	return returnType;
}