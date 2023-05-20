#include <SDL2/SDL.h>

#include <iostream>

#include "src/core/Window.h"

int main(int argc, char** argv) {
  int result = SDL_Init(SDL_INIT_EVERYTHING);
  if (result != 0) return 0;

  Window window =
      Window("Blaze Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  SDL_Delay(2500);

  SDL_Quit();
  return 0;
}