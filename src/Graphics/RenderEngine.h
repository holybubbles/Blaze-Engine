#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

class RenderEngine {
 private:
  SDL_GLContext m_context;

 public:
  RenderEngine();

  bool init(SDL_GLContext context);
  void clearColor(float r, float g, float b, float a);

  ~RenderEngine() = default;
};
