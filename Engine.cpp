#include <SDL2/SDL.h>
#include <gl/glew.h>

#include <iostream>

#include "src/Graphics/Mesh.h"
#include "src/Graphics/RenderEngine.h"
#include "src/Graphics/Shader.h"
#include "src/core/Window.h"

std::vector<float> triangle_vertices = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                                        0.0f,  0.0f,  0.5f, 0.0f};

int main(int argc, char** argv) {
  int result = SDL_Init(SDL_INIT_EVERYTHING);
  if (result != 0)
    return 0;

  WindowSettings settings;
  Window window = Window("Blaze Engine", settings);

  RenderEngine renderer;
  renderer.init(window.getContext());

  Shader shader("../../assets/Shaders/basicShader");
  Mesh triangle(triangle_vertices);

  SDL_Event windowEvent;
  while (true) {
    if (SDL_PollEvent(&windowEvent)) {
      if (windowEvent.type == SDL_QUIT)
        break;
    }
    if (windowEvent.type == SDL_KEYUP &&
        windowEvent.key.keysym.sym == SDLK_ESCAPE)
      break;

    renderer.clearColor(0.2f, 0.3f, 0.3f, 1.0f);

    shader.use();
    triangle.draw();

    window.update();
  }

  SDL_Quit();
  return 0;
}
