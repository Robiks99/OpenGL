#include"RenderMesh.h"
#include<cglm/cglm.h>
float offset = 1.0f;
bool inc = false;
ReturnType RenderMesh(struct Model* a_Model)
{
    
    // Use shader program
    glUseProgram(a_Model->shaderProgram);
	
	//glm_translate(model, vec);

	//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, &model);
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
	printf("%ff\n", offset);
	vec3 axis = { 1.0f, 0.0f, 0.0f };
	glm_mat4_identity(a_Model->rotate);
	glm_mat4_identity(a_Model->perspective);
	glm_mat4_identity(a_Model->view);
	glm_translate(a_Model->rotate, (vec3) { 0.0f, 0.0f, -5.0f });
	glm_rotate(a_Model->rotate, offset * glm_rad(90.0f), (vec3) { 1.0f, 2.0f, 4.0f });
	glm_perspective(glm_rad(75.0f),800.0f/600.0f, 0.1f, 100.0f, a_Model->perspective);
	//glm_translate(view, rotate);
	/*for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			printf("[%f]", a_Model->rotate[i][j]);

		}
		printf("\n");
	}
	printf("\n");*/

	glUniformMatrix4fv(a_Model->uniformModel, 1, GL_FALSE, &a_Model->rotate[0]);
	glUniformMatrix4fv(a_Model->uniformPerspective, 1, GL_FALSE, &a_Model->perspective[0]);
	glUniformMatrix4fv(a_Model->uniformView, 1, GL_FALSE, &a_Model->view[0]);
    // Bind vertex array object
    glBindVertexArray(a_Model->VAO);

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3*a_Model->vertexCount);


    //
    return E_OK;
}