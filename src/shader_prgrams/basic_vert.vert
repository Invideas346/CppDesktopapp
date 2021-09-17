#version 330 core

layout(location = 0) in vec2 a_position;

uniform vec2 in_offset;

void main() { gl_Position = vec4(a_position + in_offset, 0.0f, 1.0f); }