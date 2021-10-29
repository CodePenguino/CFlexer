#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <math.h>
#include <time.h>
#include <GL/glew.h>

typedef uint8_t   u8;
typedef int8_t    i8;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint64_t u64;
typedef int64_t  i64;

char* read_file(char *filename);

// Common math functions
#define degrees_to_radians(angleInDegrees) ((angleInDegrees) * M_PI / 180.0f)
/*void print_vec3_p(vec3* vector);
void print_vec3(vec3 vector);*/

float get_time_elapsed();

float benchmark_start_time;
float benchmark_end_time;

#define start_benchmark() (benchmark_start_time = (float)clock()/CLOCKS_PER_SEC)
#define stop_benchmark()  (benchmark_end_time  = (float)clock()/CLOCKS_PER_SEC)

#define benchmark_func(x) start_benchmark();\
	x;\
	stop_benchmark();\
	printf("Benchmark: %f\n", benchmark_end_time - benchmark_start_time);

// Set up the width and height of the vertices
const static GLfloat sprite_default_vertices[] = {
		0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
		0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
	-0.5f,  0.5f, 0.0f,     0.0f, 1.0f
};
const static GLuint sprite_default_indices[] = {
	0, 1, 3,
	1, 2, 3
};

#endif
