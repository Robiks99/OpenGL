#ifndef LOADMESHFROMFILE_H
#define LOADMESHFROMFILE_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Vertex.h"
#include"Model.h"

struct Vertex* LoadMeshFromFile(const char a_Path[], struct Model* a_Model);

#endif // !LOADMESHFROMFILE_H
