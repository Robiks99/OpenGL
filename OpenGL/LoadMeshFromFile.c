#include"LoadMeshFromFile.h"
#pragma warning (disable : 6262)
#define waveFrontPrecision 1000000

//Check if every component of Vectex is same
bool isVertexSame(struct Vertex vertex1, struct Vertex vertex2)
{
	if ((int)(vertex1.position[0] * waveFrontPrecision)		== (int)(vertex2.position[0] * waveFrontPrecision) &&
		(int)(vertex1.position[1] * waveFrontPrecision)		== (int)(vertex2.position[1] * waveFrontPrecision) &&
		(int)(vertex1.position[2] * waveFrontPrecision)		== (int)(vertex2.position[2] * waveFrontPrecision)&&
		(int)(vertex1.normal[0] * waveFrontPrecision)		== (int)(vertex2.normal[0] * waveFrontPrecision) &&
		(int)(vertex1.normal[1] * waveFrontPrecision)		== (int)(vertex2.normal[1] * waveFrontPrecision) &&
		(int)(vertex1.normal[2] * waveFrontPrecision)		== (int)(vertex2.normal[2] * waveFrontPrecision)&&
		(int)(vertex1.textureCoord[0] * waveFrontPrecision) == (int)(vertex2.textureCoord[0] * waveFrontPrecision) &&
		(int)(vertex1.textureCoord[1] * waveFrontPrecision) == (int)(vertex2.textureCoord[1] * waveFrontPrecision))
	{
		return true;
	}
	else
	{
		return false;
	}
}


enum ReturnType LoadMeshFromFile(const char a_Path[], struct Model* a_Model)
{
	errno_t err;
	FILE* file;
	char fileLineContent[100] = { "\0" };

	vec3 v[10000] = {0};
	vec3 vn[10000] = {0};
	vec2 vt[10000] = {0};
	uivec3 indices[10000] = { 0 };

	unsigned short int vAmount = 0;
	unsigned short int vnAmount = 0;
	unsigned short int vtAmount = 0;
	unsigned short int fAmount = 0;

	//Open file
	err = fopen_s(&file, a_Path, "r");
	if (err != 0)
	{
		printf("Error opening file. Error: %d\n", err);
		return E_NOT_OK;
	}

	//Set cursor at beggining of the file
	fseek(file, 0L, SEEK_SET);

	char value[100] = "\0";
	char* token = NULL;

	unsigned short int vCount = 0;
	unsigned short int vnCount = 0;
	unsigned short int vtCount = 0;
	unsigned short int fCount = 0;


	while (fgets(fileLineContent, 100, file))
	{
		//Split line in file
		sscanf_s(fileLineContent, "%s", value, sizeof(value));

		//Assign verts
		if (strcmp(value, "v") == 0)
		{
			sscanf_s(fileLineContent, "%*s %f %f %f",
				&v[vCount][0],
				&v[vCount][1],
				&v[vCount][2]
			);
			vCount++;
		}
		//Assign normals
		else if (strcmp(value, "vn") == 0)
		{
			sscanf_s(fileLineContent, "%*s %f %f %f",
				&vn[vnCount][0],
				&vn[vnCount][1],
				&vn[vnCount][2]
			);
			vnCount++;
		}
		//Assign texture coords
		else if (strcmp(value, "vt") == 0)
		{
			sscanf_s(fileLineContent, "%*s %f %f",
				&vt[vtCount][0],
				&vt[vtCount][1]
			);
			vtCount++;
		}
		//Assign indices
		else if (strcmp(value, "f") == 0)
		{
			sscanf_s(fileLineContent, "%*s %u/%u/%u %u/%u/%u %u/%u/%u",
				&indices[fCount + 0][0],
				&indices[fCount + 0][1],
				&indices[fCount + 0][2],
				&indices[fCount + 1][0],
				&indices[fCount + 1][1],
				&indices[fCount + 1][2],
				&indices[fCount + 2][0],
				&indices[fCount + 2][1],
				&indices[fCount + 2][2]
			);
			//Substract from indices to match OpenGL convention
			indices[fCount + 0][0]--;
			indices[fCount + 0][1]--;
			indices[fCount + 0][2]--;
			indices[fCount + 1][0]--;
			indices[fCount + 1][1]--;
			indices[fCount + 1][2]--;
			indices[fCount + 2][0]--;
			indices[fCount + 2][1]--;
			indices[fCount + 2][2]--;

			fCount += 3;
		}

	}

	//We have counted amount of variables of each type so we can alloc memory for them
	a_Model->mesh.indices = (unsigned int*)malloc(sizeof(unsigned int) * fCount);
	a_Model->mesh.vertices = (struct Vertex*)malloc(sizeof(struct Vertex) * fCount);

	unsigned int uniqueVertCount = 0;
	//Assign vertexes and indices to fit OpenGL format
	for (size_t i = 0; i < fCount; i++)
	{
		bool sameVertex = false;
		struct Vertex vertex = { 0 };
		memcpy(vertex.position, v[indices[i][0]], sizeof(vec3));
		memcpy(vertex.textureCoord, vt[indices[i][1]], sizeof(vec2));
		memcpy(vertex.normal, vn[indices[i][2]], sizeof(vec3));

		//Search if new Vertex already exist
		for (size_t j = 0; j < uniqueVertCount; j++)
		{
			if (isVertexSame(a_Model->mesh.vertices[j], vertex))
			{
				sameVertex = true;
				a_Model->mesh.indices[i] = j;
				break;
			}
		}

		//If Vertex is new just add it to an array
		if (!sameVertex)
		{
			a_Model->mesh.vertices[uniqueVertCount] = vertex;
			a_Model->mesh.indices[i] = uniqueVertCount;
			uniqueVertCount++;
		}
	}

	//Array for vertexes was allocated with number of all indices and now that we found duplicates
	//we can reduce array size
	if (a_Model->mesh.vertices != NULL)
	{
		struct Vertex *tempVector = (struct Vertex*)realloc(a_Model->mesh.vertices, sizeof(struct Vertex) * uniqueVertCount);
		if(tempVector != NULL)
		{
			a_Model->mesh.vertices = tempVector;
		}
	}
	
	//assign values to provided mesh
	a_Model->mesh.vAmount = vAmount;
	a_Model->mesh.vtAmount = vtAmount;
	a_Model->mesh.vnAmount = vnAmount;
	a_Model->mesh.fAmount = fCount;
	a_Model->mesh.verticesCount = uniqueVertCount;

	return E_OK;
}