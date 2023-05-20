#include "Window.h"

Window::Window(const std::string title, int xPos, int yPos, int width,
               int height, Uint32 flags) {
  // SDL_Window* temp_window =
  //     SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, flags);

  // if (temp_window != nullptr)
  m_window = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(
      SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, flags));
}
