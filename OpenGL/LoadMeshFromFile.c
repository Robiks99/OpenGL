#include"LoadMeshFromFile.h"
#define MAX_BUFFER 10000

struct Vertex* LoadMeshFromFile(const char a_Path[],struct Model* a_Model)
{
	errno_t err;
	FILE* file;
	char fileLineContent[100] = { "\0" };
	
	float v[MAX_BUFFER][3] = {0};
	unsigned short int vCount = 0;
	
	float vn[MAX_BUFFER][3] = {0};
	unsigned short int vnCount = 0;
	
	float vt[MAX_BUFFER][2] = {0};
	unsigned short int vtCount = 0;

	unsigned short int face[3] = {0};
	unsigned short int fCount = 0;

	struct Vertex vertices[MAX_BUFFER] = {0};

	//Open file
	err = fopen_s(&file, a_Path, "r");
	if (err != 0)
	{
		printf("Error opening file. Error: %d\n", err);
		return NULL;
	}

	fseek(file, 0L, SEEK_SET);

	char* value = NULL;
	char* faceNumber = NULL;
	char* token = NULL;
	char* token2 = NULL;
	//Go through every line of file
	while (fgets(fileLineContent, 100, file))
	{
		//Split line in file
		value = strtok_s(fileLineContent, " ", &token);

		//Assign verts
		if (strcmp(value, "v") == 0)
		{
			for (unsigned short int i = 0; i < 3; i++)
			{
				value = strtok_s(NULL, " ", &token);
				v[vCount][i] = (float)atof(value);
			}
			vCount++;
		}
		//Assign normals
		else if (strcmp(value, "vn") == 0)
		{
			for (unsigned short int i = 0; i < 3; i++)
			{
				value = strtok_s(NULL, " ", &token);
				vn[vnCount][i] = atof(value);
			}
			vnCount++;
		}
		//Assign texture coords
		else if (strcmp(value, "vt") == 0)
		{
			for (unsigned short int i = 0; i < 2; i++)
			{
				value = strtok_s(NULL, " ", &token);
				vt[vtCount][i] = atof(value);
			}
			vtCount++;
		}
		//Match vertices with indices
		else if (strcmp(value, "f") == 0)
		{

			for (unsigned short int i = 0; i < 3; i++)
			{
				//Get indices
				value = strtok_s(NULL, " ", &token);
				faceNumber = strtok_s(value, "/", &token2);

				//Store indices for one polygon
				for (unsigned short j = 0; j < 3; j++)
				{
					face[j] = atoi(faceNumber);
					faceNumber = strtok_s(NULL, "/", &token2);
				}
				//Assign correct vertex position according to indices
				for (unsigned short int j = 0; j < 3; j++)
				{
					vertices[fCount].position[j] = v[face[0]-1][j];
				}
				//Assign correct normals according to indices
				for (unsigned short int j = 0; j < 3; j++)
				{
					vertices[fCount].normal[j] = vn[face[2]-1][j];
				}
				//Assign correct texture coords according to indices
				for (unsigned short int j = 0; j < 2; j++)
				{
					vertices[fCount].textureCoord[j] = vn[face[1]-1][j];
				}
				fCount++;
			}
			
		}

	}

	struct Vertex* polygonsPtr = (struct Polygon*)malloc(sizeof(struct Vertex) * fCount);
	if (!polygonsPtr)
	{
		return NULL;
	}

	for (unsigned short int i = 0; i < fCount; i++)
	{
		
		for (unsigned short int j = 0; j < 3; j++)
		{
			polygonsPtr[i].position[j] = vertices[i].position[j];
		}
		for (unsigned short int j = 0; j < 3; j++)
		{
			polygonsPtr[i].normal[j] = vertices[i].normal[j];
		}
		for (unsigned short int j = 0; j < 2; j++)
		{
			polygonsPtr[i].textureCoord[j] = vertices[i].textureCoord[j];
		}
	}
	
	a_Model->mesh.vertices = polygonsPtr;
	a_Model->vertexCount = fCount;


	return polygonsPtr;
}