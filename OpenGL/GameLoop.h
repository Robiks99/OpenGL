#ifndef GAMELOOP_H
#define GAMELOOP_H

#include<stdio.h>

#include"Database.h"
#include"ReturnType.h"
#include"GameInit.h"
#include"GameEvent.h"
#include"GameUpdate.h"
#include"GameRender.h"

ReturnType GameLoop(struct Database* a_database);

#endif // !GAMELOOP_H
