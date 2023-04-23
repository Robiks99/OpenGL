#include"RenderMesh.h"

ReturnType RenderMesh(struct Model a_Mesh)
{
    // Use shader program
    glUseProgram(a_Mesh.shaderProgram);

    // Bind vertex array object
    glBindVertexArray(a_Mesh.VAO);

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

    return E_OK;
}