#include"CreateShaderProgram.h"

ReturnType CreateShaderProgram(struct Model* a_Model)
{
    a_Model->shaderProgram = glCreateProgram();
    glAttachShader(a_Model->shaderProgram, a_Model->vertShader);
    glAttachShader(a_Model->shaderProgram, a_Model->fragShader);
    glLinkProgram(a_Model->shaderProgram);

    // Delete shader objects
    glDeleteShader(a_Model->vertShader);
    glDeleteShader(a_Model->fragShader);

    return E_OK;
}