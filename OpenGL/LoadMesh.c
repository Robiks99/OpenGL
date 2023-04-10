#include"LoadMesh.h"

ReturnType LoadMesh(float a_Vertices[], int a_VerticesAmount, struct Mesh* a_Mesh)
{

    // Create vertex buffer object and vertex array object
    glGenVertexArrays(1, &a_Mesh->VAO);
    glGenBuffers(1, &a_Mesh->VBO);

    // Bind vertex array object and vertex buffer object
    glBindVertexArray(a_Mesh->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, a_Mesh->VBO);

    // Copy vertex data to buffer
    glBufferData(GL_ARRAY_BUFFER, a_VerticesAmount, a_Vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    printf("VAO: %d\n", a_Mesh->VAO);
    printf("VBO: %d\n", a_Mesh->VBO);
	return E_OK;
}