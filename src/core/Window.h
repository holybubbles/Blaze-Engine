#pragma once
#include <SDL2/SDL.h>

#include <memory>
#include <string>

struct WindowSettings {
  int xPos = SDL_WINDOWPOS_CENTERED;
  int yPos = SDL_WINDOWPOS_CENTERED;
  int width = 640;
  int height = 480;
  Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
};

class Window {
 private:
  struct SDLWindowDestroyer {
    void operator()(SDL_Window* w) const { SDL_DestroyWindow(w); }
  };

  std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_window;
  SDL_GLContext m_context;

 public:
  Window(const std::string title,
         int xPos,
         int yPos,
         int width,
         int height,
         Uint32 flags);

  Window(const std::string& title, WindowSettings settings);
  ~Window();

  const std::unique_ptr<SDL_Window, SDLWindowDestroyer>& getWindow() {
    return m_window;
  }

  const SDL_GLContext getContext() { return m_context; }

  void update() { SDL_GL_SwapWindow(m_window.get()); }
};
