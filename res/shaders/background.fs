#version 330 core

out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float aspectRatio;

void main()
{
	FragColor = texture2D(ourTexture, TexCoord * vec2(aspectRatio, 1.0f));
}