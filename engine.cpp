#include <SDL2/SDL.h>

#include <iostream>

int main(int argc, char** argv) {
  int result = SDL_Init(SDL_INIT_EVERYTHING);
  if (result != 0) return 0;

  SDL_Window* window = SDL_CreateWindow(
      "Blaze Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (window == NULL) return 0;

  SDL_Delay(2500);

  SDL_Quit();
  return 0;
}