cmake_minimum_required(VERSION 3.15.0)
project(GL3H VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

###############################################################################
## GLOBAL VARIABLES
###############################################################################
if (UNIX)
add_compile_options(-Wall -Wextra -Werror)
elseif(WIN32)
add_compile_options(/W4 /WX)
endif(UNIX)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

###############################################################################
## GL3H LIBRARY - OpenGL v3.3+ Helper library
###############################################################################
add_library(GL3H SHARED src/index_buffer.cpp
                src/attrib_info.cpp
                src/renderer.cpp
                src/shader.cpp
                src/texture.cpp
                src/vertex_array.cpp
                src/vertex_buffer.cpp
                src/vertex_layout.cpp
                src/gl3h.cpp
                )

target_include_directories(GL3H PRIVATE vendor include)

if(WIN32)
target_compile_definitions(GL3H PRIVATE GL3H_DLL_EXPORT)
target_link_libraries(GL3H ${PROJECT_SOURCE_DIR}/lib/win/GLEW/glew32.lib opengl32.lib)
target_link_options(GL3H PRIVATE /NODEFAULTLIB:LIBCMT)
endif(WIN32)