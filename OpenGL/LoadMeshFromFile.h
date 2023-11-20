#ifndef LOADMESHFROMFILE_H
#define LOADMESHFROMFILE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Vertex.h"
#include"Model.h"
#include"ReturnType.h"

/*
Function: LoadMeshFromFile
Purpose: Parse file and store it in Model
Parameters:
	-const char a_Path[] (IN)
		provide path to wavefront(.obj) file to parse it into Model struct.
	-struct Model* a_Model (OUT)
		store all neccesery informations while parsing
Problems:
	-This parser is pretty basic and will need some work
	-Limited amount of vertices while parsing
*/
enum ReturnType LoadMeshFromFile(const char a_Path[], struct Model* a_Model);

#endif // !LOADMESHFROMFILE_H
