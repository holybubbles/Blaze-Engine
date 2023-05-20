#pragma once
#include <SDL2/SDL.h>

#include <memory>
#include <string>

class Window {
 private:
  struct SDLWindowDestroyer {
    void operator()(SDL_Window* w) const { SDL_DestroyWindow(w); }
  };

  std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_window;

 public:
  Window(const std::string title, int xPos, int yPos, int width, int height,
         Uint32 flags);
  ~Window() = default;

  const std::unique_ptr<SDL_Window, SDLWindowDestroyer>& get_window() {
    return m_window;
  }
};
