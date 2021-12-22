#include "renderer.h"
#include "../ecs/components/transform_component.h"
#include "window.h"

float SPRITE_RESOLUTION;
Camera2dComponent camera;

// Setup for the camera
void renderer_setup(float sprite_res)
{
	camera2d_init(&camera, (v2) { 0.0f, 0.0f }, 0.0f);
	SPRITE_RESOLUTION = 1.0f/sprite_res;
}

// Update the projection matrix (done when the window is resized)
void renderer_update_camera_projection()
{
	camera.projMat = m4_ortho(-window.aspectRatio, window.aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
}

// Use the shader specified in the input
void renderer_use_shader(Shader shader)
{
	render_shader = shader;
	shader_use(render_shader);
}

// Draw a orthographically projected sprite
void draw_sprite(SpriteComponent* sprite, Transform2dComponent* transform)
{
	shader_set_m4(render_shader, "transform", transform2d_get_ortho(&camera, transform));

	// The name of this function is definitely not confusing...
	// sprite_draw(sprite);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, sprite->texture_id);

	glBindVertexArray(sprite->VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}