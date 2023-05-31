#include "Window.h"

#include <gl/glew.h>

Window::Window(const std::string title, int xPos, int yPos, int width,
               int height, Uint32 flags) {
  m_window = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(
      SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, flags));

  m_context = SDL_GL_CreateContext(m_window.get());
  glViewport(0, 0, width, height);
}

Window::Window(const std::string& title, WindowSettings settings) {
  m_window = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(
      SDL_CreateWindow(title.c_str(), settings.xPos, settings.yPos,
                       settings.width, settings.height, settings.flags));

  m_context = SDL_GL_CreateContext(m_window.get());
}

Window::~Window() { SDL_GL_DeleteContext(m_context); }