cmake_minimum_required(VERSION 3.24.2)
project(BlazeEngine CXX)

find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package(box2d REQUIRED)
find_package(asio REQUIRED)
find_package(stb REQUIRED)

set(SOURCES 
      Engine.cpp
      src/core/Window.cpp
      src/Graphics/RenderEngine.cpp
      src/Graphics/Shader.cpp
      src/Graphics/Mesh.cpp
      )

add_executable(BlazeEngine ${SOURCES})

# target_include_directories(BlazeEngine PUBLIC external/glew/include/)
target_compile_features(BlazeEngine PUBLIC cxx_std_20)

target_link_libraries(BlazeEngine 
      SDL2::SDL2
      SDL2::SDL2main
      opengl::opengl
      GLEW::GLEW
      glm::glm
      box2d::box2d
      asio::asio
      stb::stb)