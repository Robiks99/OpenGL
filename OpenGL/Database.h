#ifndef DATABASE_H
#define DATABASE_H

#include"GameLoopDatabase.h"
#include"System.h"
#include"ModelsId.h"

struct Database
{
	struct System system;
	struct GameLoopDatabase gameLoopDatabase;
	struct Model models[numberOfModels];
};

#endif // !DATABASE_H
