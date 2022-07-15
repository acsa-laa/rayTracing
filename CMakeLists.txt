cmake_minimum_required(VERSION 3.22)
project(rayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(rayTracing main.cpp RunningOptions.h color.h film.h ray.h tinyxml2.h vec3.h tinyxml2.cpp camera.cpp camera.h parser.cpp parser.h PerspectiveCamera.cpp PerspectiveCamera.h OrthographicCamera.cpp OrthographicCamera.h primitive.h sphere.h sphere.cpp material.cpp material.h flatIntegrator.cpp flatIntegrator.h dephMathIntegrator.cpp dephMathIntegrator.h normalIntegrator.cpp normalIntegrator.h Integrator.cpp Integrator.h primitive.cpp surfel.h point2.h ambiente.h light.h point.h spot.h blinnMaterial.h blinnPhongIntegrator.cpp blinnPhongIntegrator.h directional.h)
