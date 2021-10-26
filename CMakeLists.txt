cmake_minimum_required(VERSION 3.2)
project(CFlexer)

set(OpenGL_GL_PREFERENCE GLVND)
add_definitions(-fPIC)

# Load all header files
file(GLOB_RECURSE HDRS
    ${CFlexer_SOURCE_DIR}/src/*.h
    ${CFlexer_SOURCE_DIR}/src/*.hpp
)

# Load all source files
file(GLOB_RECURSE SRCS
    ${CFlexer_SOURCE_DIR}/src/*.cpp
    ${CFlexer_SOURCE_DIR}/src/*.c
)

add_executable(CFlexer ${HDRS} ${SRCS})

target_include_directories(CFlexer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/")

# Find the libraries that are being used
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Link the libraries used
target_link_libraries(CFlexer -lm glfw)
target_link_libraries(CFlexer -lm ${GLEW_LIBRARIES})
target_link_libraries(CFlexer -lm ${OPENGL_LIBRARIES})

# Include the libraries used
target_include_directories(CFlexer PRIVATE glfw)
target_include_directories(CFlexer PRIVATE ${GLEW_INCLUDE_DIRS})
target_include_directories(CFlexer PRIVATE ${OPENGL_INCLUDE_DIRS})
