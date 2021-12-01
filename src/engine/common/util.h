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

typedef float f32;
typedef double f64;

char* read_file(char *filename);

// Common math functions
#define degrees_to_radians(angleInDegrees) ((angleInDegrees) * M_PI / 180.0f)
#define radians_to_degrees(angleInRadians) ((angleInRadians) * 180.0f / M_PI)

float get_time_elapsed();

float benchmark_start_time;
float benchmark_end_time;

#define start_benchmark() (benchmark_start_time = (float)clock()/CLOCKS_PER_SEC)
#define stop_benchmark()  (benchmark_end_time  = (float)clock()/CLOCKS_PER_SEC)

#define benchmark_func(x) start_benchmark();\
	x;\
	stop_benchmark();\
	printf("Benchmark: %f\n", benchmark_end_time - benchmark_start_time);

#define max(a, b) ({\
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a, b) ({\
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b; })

#define clamp(x, mn, mx) ({\
    __typeof__ (x) _x = (x); \
    __typeof__ (mn) _mn = (mn); \
    __typeof__ (mx) _mx = (mx); \
    max(_mn, min(_mx, _x)); })

// TODO: Set up the width and height of the vertices depending on resolution
const static GLfloat sprite_default_vertices[16] = {
	 1.0f,  1.0f,    1.0f, 1.0f,
	 1.0f, -1.0f,    1.0f, 0.0f,
	-1.0f, -1.0f,    0.0f, 0.0f,
 	-1.0f,  1.0f,    0.0f, 1.0f
};

const static GLuint sprite_default_indices[6] = {
	0, 1, 3,
	1, 2, 3
};

#endif
