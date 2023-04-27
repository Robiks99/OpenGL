#include"LoadMesh.h"



ReturnType LoadMesh(GLfloat a_Vertices[], int a_VerticesAmount, struct Model* a_Model)
{

    // Create vertex buffer object and vertex array object
    glGenVertexArrays(1, &a_Model->VAO);
    glGenBuffers(1, &a_Model->VBO);

    // Bind vertex array object and vertex buffer object
    glBindVertexArray(a_Model->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, a_Model->VBO);
    
    // Copy vertex data to buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Vertex) * a_Model->vertexCount, a_Model->mesh.vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    // Vertex position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)0);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    printf("VAO: %d\n", a_Model->VAO);
    printf("VBO: %d\n", a_Model->VBO);
	return E_OK;
}