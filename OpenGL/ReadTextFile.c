#include"ReadTextFile.h"

char* ReadTextFile(const char a_Path[])
{
	errno_t err;
	FILE* file;
	char fileContent[2048] = {"\0"};

	
	//Open file
	err = fopen_s(&file, a_Path, "r");
	if (err != 0)
	{
		printf("Error opening file. Error: %d\n", err);
		return NULL;
	}

	//fread_s(fileContent,2048 , sizeof(char), 2048, file);
	fread(fileContent, sizeof(char), 2048, file);

	// Close file
	fclose(file);

	//Check amount of characters in file.
	unsigned int fileSize = 0;
	while (fileContent[fileSize] != '\0')
	{
		fileSize++;
	}

	char* fileContentPtr = (char*)malloc(sizeof(char) * fileSize + 1);
	if (!fileContentPtr)
	{
		printf("Error allocating memory");
		return NULL;
	}

	//Copy file from array to ptr
	for (unsigned int i = 0; i < fileSize; i++)
	{
		fileContentPtr[i] = fileContent[i];
	}
	 // Add null terminator to char array
	fileContentPtr[fileSize] = '\0';

	//printf("file ptr:\n%s\n", fileContentPtr);
	//printf("file:\n%s\n", fileContent);

	return fileContentPtr;
}
