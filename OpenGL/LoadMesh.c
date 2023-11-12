#include"LoadMesh.h"

ReturnType LoadMesh(struct Model* a_Model)
{
    // Create vertex buffer object and vertex array object
    glGenVertexArrays(1, &a_Model->VAO);
    glGenBuffers(1, &a_Model->VBO);
    glGenBuffers(1, &a_Model->EBO);

    // Calculate the total size of the vertex data
    size_t vertexDataSize = sizeof(struct Vertex) * a_Model->mesh.verticesCount;

    size_t indicesDataSize = sizeof(unsigned int) * a_Model->mesh.fAmount;

    // Bind vertex array object and vertex buffer object
    glBindVertexArray(a_Model->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, a_Model->VBO);

    // Allocate memory for the vertex data
    glBufferData(GL_ARRAY_BUFFER, vertexDataSize, a_Model->mesh.vertices, GL_STATIC_DRAW);

    // Copy indices into buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, a_Model->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesDataSize, a_Model->mesh.indices, GL_STATIC_DRAW);

    // Set vertex attribute pointers for positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const void*)0);

    // Set vertex attribute pointers for texture coordinates
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const void*)(sizeof(vec3)));

    // Set vertex attribute pointers for normals
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (const void*)((sizeof(vec3)) + (sizeof(vec2))));
    

    //Bind buffers
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    //glBindVertexArray(0);


    return E_OK;
}

