#include"GameLoop.h"

ReturnType GameLoop(struct Database* a_database)
{
	ReturnType returnType = E_NOT_OK;

	returnType = GameInit(a_database);
	if (returnType != E_OK)
	{
		printf("Error: GameInit failed\n");
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