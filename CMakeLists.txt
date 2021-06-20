cmake_minimum_required(VERSION 3.0.0)
project(2D_Line_Drawing VERSION 0.1.0)

include_directories(. OpenGL/freeglut/include OpenGL/glew/include)
link_directories(OpenGL OpenGL/freeglut/lib OpenGL/glew/lib/Release/Win32)
link_libraries("libfreeglut.a" "glew32.lib" "opengl32.lib" "glu32.lib")

aux_source_directory(. SOURCE_LIST)
aux_source_directory(./Elems SOURCE_LIST)
aux_source_directory(./Elems/Line SOURCE_LIST)
aux_source_directory(./WM SOURCE_LIST)

add_executable(2D_Line_Drawing "${SOURCE_LIST}")