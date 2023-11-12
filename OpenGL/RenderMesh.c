#include"RenderMesh.h"
#include<cglm/cglm.h>
float offset = 1.0f;
bool inc = false;
ReturnType RenderMesh(struct Model* a_Model)
{
    
    // Use shader program
    glUseProgram(a_Model->shaderProgram);
	
	if (inc)
	{
		offset += 0.01f;
		if (offset > 10.0f)
			inc = !inc;
	}
	else
	{
		offset -= 0.01f;
		if (offset < -10.0f)
			inc = !inc;
	}

	glm_mat4_identity(a_Model->rotate);
	glm_mat4_identity(a_Model->perspective);
	glm_mat4_identity(a_Model->view);
	glm_translate(a_Model->rotate, (vec3) { 0.0f, offset, -5.0f });
	glm_rotate(a_Model->rotate, offset * glm_rad(90.0f), (vec3) { 0.0f, 40.0f, 0.0f });
	glm_perspective(glm_rad(75.0f),800.0f/600.0f, 0.1f, 100.0f, a_Model->perspective);

	glUniformMatrix4fv(a_Model->uniformModel, 1, GL_FALSE, &a_Model->rotate[0]);
	glUniformMatrix4fv(a_Model->uniformPerspective, 1, GL_FALSE, &a_Model->perspective[0]);
	glUniformMatrix4fv(a_Model->uniformView, 1, GL_FALSE, &a_Model->view[0]);
    // Bind vertex array object
    glBindVertexArray(a_Model->VAO);

    // Draw the triangle
	glDrawElements(GL_TRIANGLES, a_Model->mesh.fAmount, GL_UNSIGNED_INT, 0);

    return E_OK;
}