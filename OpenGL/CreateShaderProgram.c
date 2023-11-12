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

    a_Model->uniformModel = glGetUniformLocation(a_Model->shaderProgram, "model");
    a_Model->uniformPerspective = glGetUniformLocation(a_Model->shaderProgram, "perspective");
    a_Model->uniformView = glGetUniformLocation(a_Model->shaderProgram, "view");

    return E_OK;
}