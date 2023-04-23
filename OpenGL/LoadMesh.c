#include"LoadMesh.h"

ReturnType LoadMesh(float a_Vertices[], int a_VerticesAmount, struct Model* a_Model)
{

    // Create vertex buffer object and vertex array object
    glGenVertexArrays(1, &a_Model->VAO);
    glGenBuffers(1, &a_Model->VBO);

    // Bind vertex array object and vertex buffer object
    glBindVertexArray(a_Model->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, a_Model->VBO);

    // Copy vertex data to buffer
    glBufferData(GL_ARRAY_BUFFER, a_VerticesAmount, a_Vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    printf("VAO: %d\n", a_Model->VAO);
    printf("VBO: %d\n", a_Model->VBO);
	return E_OK;
}