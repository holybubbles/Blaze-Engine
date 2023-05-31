#include "RenderEngine.h"

RenderEngine::RenderEngine(/* args */) {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
}

bool RenderEngine::init(SDL_GLContext context) {
  m_context = context;

  glewExperimental = GL_TRUE;
  return glewInit() == GLEW_OK;
}

void RenderEngine::clearColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
}