#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 tex;
uniform mat4 model;
uniform mat4 perspective;
uniform mat4 view;

out vec2 TexCoord;
out vec4 vCol;

void main()
{
    gl_Position =  perspective * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vCol = vec4(clamp(aPos, 0.0f, 1.0f), 1.0);
    TexCoord = tex;
}