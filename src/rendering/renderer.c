#include "renderer.h"
#include "../ecs/transform.h"
#include "window.h"

Camera2d camera;

// Setup for the camera
void renderer_setup()
{
	camera2d_init(&camera, (v2){ 0.0f, 0.0f }, 0.0f);
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
void draw_sprite(Sprite sprite)
{
	shader_set_m4(render_shader, "transform", transform2d_get_ortho(&camera, &sprite.transform));

	// The name of this function is definitely not confusing...
	sprite_draw(sprite);
}