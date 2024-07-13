#include "maze.h"
#include <stdio.h>

/**
 * init_SDL - Initializes SDL
 * @window: Pointer to the SDL window
 * @renderer: Pointer to the SDL renderer
 * 
 * Return: 0 on success, 1 on failure
 */
int init_SDL(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return (1);
    }

    *window = SDL_CreateWindow("The Maze",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (*window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return (1);
    }

    SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return (0);
}

/**
 * close_SDL - Shuts down SDL
 * @window: Pointer to the SDL window
 * @renderer: Pointer to the SDL renderer
 */
void close_SDL(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

/**
 * draw_walls - Draws walls using SDL
 * @renderer: Pointer to the SDL renderer
 * @posX: X position of the camera
 * @posY: Y position of the camera
 * @angle: Angle of the camera
 */
void draw_walls(SDL_Renderer *renderer, float posX, float posY, float angle)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    /* Using the parameters to avoid warnings */
    (void)posX;
    (void)posY;
    (void)angle;

    SDL_Rect wall = {SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25, 50, 50};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &wall);

    SDL_RenderPresent(renderer);
}
