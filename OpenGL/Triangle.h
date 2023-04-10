#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<GL/glew.h>

GLfloat Triangle[] = 
{
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f
};

#endif // !TRIANGLE_H



// Create vertex buffer object and vertex array object
    glGenVertexArrays(1, &a_Mesh.VAO);
    glGenBuffers(1, &a_Mesh.VBO);

    // Bind vertex array object and vertex buffer object
    glBindVertexArray(a_Mesh.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, a_Mesh.VBO);

    // Copy vertex data to buffer
    glBufferData(GL_ARRAY_BUFFER, a_VerticesAmount, a_Vertices, GL_STATIC_DRAW);

    printf("vert: %d\n", a_VerticesAmount);
    printf("sizeof vert: %d\n", sizeof(a_Vertices));
    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	a_Mesh.vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(a_Mesh.vertShader, 1, &a_VertShader, NULL);
	glCompileShader(a_Mesh.vertShader);

	a_Mesh.fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(a_Mesh.fragShader, 1, &a_FragShader, NULL);
	glCompileShader(a_Mesh.fragShader);

	a_Mesh.shaderProgram = glCreateProgram();
    glAttachShader(a_Mesh.shaderProgram, a_Mesh.vertShader);
    glAttachShader(a_Mesh.shaderProgram, a_Mesh.fragShader);
    glLinkProgram(a_Mesh.shaderProgram);

    // Delete shader objects
    glDeleteShader(a_Mesh.vertShader);
    glDeleteShader(a_Mesh.fragShader);

	glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

	// Set the framebuffer size callback
		glfwSetFramebufferSizeCallback(a_database->system.window.window, framebuffer_size_callback);

		while(1)
		{
			glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(a_Mesh.shaderProgram);

    // Bind vertex array object
    glBindVertexArray(a_Mesh.VAO);

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);

	glfwSwapBuffers(a_database->system.window.window);
	
		}