#include"RenderMesh.h"

float offset = 1.0f;
bool inc = false;
ReturnType RenderMesh(struct Model a_Model)
{
    
    
    
    // Use shader program
    glUseProgram(a_Model.shaderProgram);
	
	//glm_translate(model, vec);

	//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, &model);
	if (inc)
	{
		offset += 0.01f;
		if (offset > 1.0f)
			inc = !inc;
	}
	else
	{
		offset -= 0.01f;
		if (offset < -1.0f)
			inc = !inc;
	}
	printf("%ff\n", offset);
	glUniform1fv(a_Model.uniformModel, 1, &offset);
    // Bind vertex array object
    glBindVertexArray(a_Model.VAO);

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3*12);


    //
    return E_OK;
}