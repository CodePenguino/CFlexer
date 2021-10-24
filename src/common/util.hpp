#pragma once

#include <stdint.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

static float benchmark_start_time;
static float benchmark_end_time;

#define start_benchmark() (benchmark_start_time = (float)clock()/CLOCKS_PER_SEC)
#define stop_benchmark()  (benchmark_end_time  = (float)clock()/CLOCKS_PER_SEC)

#define benchmark_func(x) start_benchmark();\
	x;\
	stop_benchmark();\
	printf("Benchmark: %f\n", benchmark_end_time - benchmark_start_time);
