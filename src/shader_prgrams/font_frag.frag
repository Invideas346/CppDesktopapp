#version 120

varying vec2 v_tex_coord;

uniform sampler2D u_texture;

void main()
{
    vec4 color = texture2D(u_texture, v_tex_coord).a;
    if (color.x == 0.0f && color.y == 0.0f && color.z == 0.0f)
    {
        color.w = 0.0f;
    }
    gl_FragColor = color;
}