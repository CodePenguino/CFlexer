#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float windowAspectRatio;
uniform vec2 texture_offset;

void main()
{
	FragColor = texture2D(ourTexture, TexCoord * vec2(windowAspectRatio, 1.0) + vec2(0.2, 0.0));
}