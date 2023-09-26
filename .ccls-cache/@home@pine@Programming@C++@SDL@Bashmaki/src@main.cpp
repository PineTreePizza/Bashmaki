#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char *argv[]) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cerr << "Failed to initialize SDL, SDL_Error: " << SDL_GetError()
              << std::endl;

  SDL_Window *window =
      SDL_CreateWindow("Башмаки", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 600, 603, SDL_WINDOW_RESIZABLE);

  SDL_Surface *image = IMG_Load("../images/bashmaki.png");

  SDL_Renderer *renderer = SDL_CreateRenderer(
      window, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_SOFTWARE);

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

  SDL_RenderCopy(renderer, texture, NULL, NULL);

  SDL_RenderPresent(renderer);

  SDL_Rect destRect; // Destination rectangle for rendering
  destRect.x = 0;
  destRect.y = 0;

  SDL_Event e;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        running = false;
      } else if (e.type == SDL_WINDOWEVENT) {
        if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
          // If the window is resized, update the destination rectangle
          SDL_GetWindowSize(window, &destRect.w, &destRect.h);
        }
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  window = NULL;
  IMG_Quit();
  SDL_Quit();

  std::clog << "Closed successfully!";

  return 0;
}
