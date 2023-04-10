#include"CreateShaderProgram.h"

ReturnType CreateShaderProgram(struct Mesh* a_Mesh)
{
    a_Mesh->shaderProgram = glCreateProgram();
    glAttachShader(a_Mesh->shaderProgram, a_Mesh->vertShader);
    glAttachShader(a_Mesh->shaderProgram, a_Mesh->fragShader);
    glLinkProgram(a_Mesh->shaderProgram);

    // Delete shader objects
    glDeleteShader(a_Mesh->vertShader);
    glDeleteShader(a_Mesh->fragShader);

    return E_OK;
}