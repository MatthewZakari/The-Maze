#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int init_SDL(SDL_Window **window, SDL_Renderer **renderer);
void close_SDL(SDL_Window *window, SDL_Renderer *renderer);
void draw_walls(SDL_Renderer *renderer, float posX, float posY, float angle);

#endif /* MAZE_H */

