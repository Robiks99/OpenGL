#include"ReadTextFile.h"

ReturnType ReadTextFile(const char a_Path[], char* a_ProgramContent)
{
	ReturnType returnType = E_NOT_OK;
	errno_t err;
	FILE* file;
	err = fopen_s(&file, a_Path, "rb");
	if (err != 0)
	{
		printf("Error opening file. Error: %d\n", err);
	}

	if (file)
	{
		returnType = E_OK;

        // Determine file size
        fseek(file, 0, SEEK_END);
        int fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Allocate memory for char array
        //char* fileContents = (char*)malloc(1000 + 1);
        //fileContents = "\0";
        //char a_ProgramContent[1000];
        a_ProgramContent = (char*)malloc(1000 + 1);
       /* if (fileContents == NULL) {
            printf("Error allocating memory.\n");
            fclose(file);
        }*/

        // Read file into char array
        unsigned int bytesRead = fread(a_ProgramContent, sizeof(char), fileSize, file);
        if (bytesRead != fileSize) {
            printf("Error reading file.\n");
            //free(fileContents);
            fclose(file);
        }

        // Add null terminator to char array
        a_ProgramContent[fileSize] = '\0';

        // Close file and return char array
        fclose(file);

        //a_ProgramContent = fileContents;
	}
	
	return returnType;
}
