cmake_minimum_required(VERSION 3.24.2)
project(BlazeEngine CXX)

find_package(SDL2 REQUIRED)
find_package(GLAD REQUIRED)
find_package(glm REQUIRED)
find_package(box2d REQUIRED)
find_package(asio REQUIRED)
find_package(stb REQUIRED)

add_executable(BlazeEngine engine.cpp)
target_link_libraries(BlazeEngine 
      SDL2::SDL2
      SDL2::SDL2main
      glad::glad
      opengl::opengl
      glm::glm
      box2d::box2d
      asio::asio
      stb::stb)
