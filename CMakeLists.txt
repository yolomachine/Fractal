cmake_minimum_required(VERSION 3.10)
project(Fractal)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fractal main.cpp Settings.h Window.h Window.cpp Utils.h Shader.h Shader.cpp GLobject.h GLobject.cpp)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3 glew)
include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(Fractal ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARIES})

