cmake_minimum_required(VERSION 3.22)
project(rayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(rayTracing main.cpp api.h color.h film.h ray.h tinyxml2.h vec3.h tinyxml2.cpp parser.cpp parser.h camera.cpp camera.h RunningOptions.h)
