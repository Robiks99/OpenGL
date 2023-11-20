#include"RenderMesh.h"

ReturnType RenderMesh(struct Entity* a_entity, struct Window a_window)
{
	struct Model model = a_entity->model;
    // Use shader program
    glUseProgram(model.shaderProgram);

	
	glm_translate(model.rotate, a_entity->position);
	glm_rotate(model.rotate, glm_rad(a_entity->rotation[0]), (vec3) { 1.0f, 0.0f, 0.0f });
	glm_rotate(model.rotate, glm_rad(a_entity->rotation[1]), (vec3) { 0.0f, 1.0f, 0.0f });
	glm_rotate(model.rotate, glm_rad(a_entity->rotation[2]), (vec3) { 0.0f, 0.0f, 1.0f });
	glm_perspective(glm_rad(75.0f),(float)a_window.bufferWidth/(float)a_window.bufferHeight, 0.1f, 100.0f, model.perspective);

	glUniformMatrix4fv(model.uniformModel, 1, GL_FALSE, &model.rotate[0]);
	glUniformMatrix4fv(model.uniformPerspective, 1, GL_FALSE, &model.perspective[0]);
	glUniformMatrix4fv(model.uniformView, 1, GL_FALSE, &model.view[0]);
    // Bind vertex array object
    glBindVertexArray(model.VAO);

    // Draw the triangle
	glDrawElements(GL_TRIANGLES, model.mesh.fAmount, GL_UNSIGNED_INT, 0);

    return E_OK;
}