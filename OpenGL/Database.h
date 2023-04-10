#ifndef DATABASE_H
#define DATABASE_H

#include"GameLoopDatabase.h"
#include"System.h"

struct Database
{
	struct System system;
	struct GameLoopDatabase gameLoopDatabase;
};

#endif // !DATABASE_H
