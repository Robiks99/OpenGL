#version 330 core
out vec4 FragColor;
uniform float model;

void main()
{

    FragColor = vec4(1.0f - model, 1.0f, 0.0f, 1.0f);
}