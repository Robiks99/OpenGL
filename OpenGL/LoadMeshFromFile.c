#include"LoadMeshFromFile.h"
#define MAX_BUFFER 250

struct Polygon* LoadMeshFromFile(const char a_Path[])
{
	errno_t err;
	FILE* file;
	char fileLineContent[100] = { "\0" };
	
	float v[MAX_BUFFER][3] = {0};
	unsigned short int vCount = 0;
	
	float vn[MAX_BUFFER][3] = {0};
	unsigned short int vnCount = 0;
	
	float vt[MAX_BUFFER][3] = {0};
	unsigned short int vtCount = 0;

	unsigned short int face[3] = {0};
	unsigned short int fCount = 0;

	struct Polygon polygons[MAX_BUFFER] = {0};

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
		printf("|%s|\n",value);
		
		//Assign verts
		if (strcmp(value, "v") == 0)
		{
			for (unsigned short int i = 0; i < 3; i++)
			{
				value = strtok_s(NULL, " ", &token);
				v[vCount][i] = (float)atof(value);
				printf("tab: %f\n", v[vCount][i]);

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
				printf("tab: %f\n", vn[vnCount][i]);

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
				printf("tab: %f\n", vt[vtCount][i]);

			}
			vtCount++;
		}
		else if (strcmp(value, "f") == 0)
		{
			for (unsigned short int i = 0; i < 3; i++)
			{
				value = strtok_s(NULL, " ", &token);
				faceNumber = strtok_s(value, "/", &token2);
				printf("tab1: %s\n", value);
				for (unsigned short j = 0; j < 3; j++)
				{
					printf("tab2: %s\n", faceNumber);
					//value = strtok_s(NULL, "/", &token);
					//face[fCount][j] = atof(value);
					face[j] = atoi(faceNumber);
					faceNumber = strtok_s(NULL, "/", &token2);
				}
				for (unsigned short int j = 0; j < 3; j++)
				{
					polygons[fCount].vectors[i][j] = v[face[0]][j];
				}
				for (unsigned short int j = 0; j < 3; j++)
				{
					polygons[fCount].normal[j] = vn[face[2]][j];
				}
				for (unsigned short int j = 0; j < 2; j++)
				{
					polygons[fCount].textureCoord[j] = vn[face[1]][j];
				}
				fCount++;
			}
		}

	}
	
	return polygons;
}