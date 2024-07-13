#include <stdio.h>
#include "maze.h"

/**
 * handle_events - Handles keyboard events to move and rotate the camera
 * @quit: Pointer to the quit flag
 * @posX: Pointer to the camera's X position
 * @posY: Pointer to the camera's Y position
 * @angle: Pointer to the camera's angle
 */
void handle_events(int *quit, float *posX, float *posY, float *angle)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            *quit = 1;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                *quit = 1;
                break;
            case SDLK_LEFT:
                *angle -= 0.1;
                break;
            case SDLK_RIGHT:
                *angle += 0.1;
                break;
            case SDLK_UP:
                *posX += 0.1 * cos(*angle);
                *posY += 0.1 * sin(*angle);
                break;
            case SDLK_DOWN:
                *posX -= 0.1 * cos(*angle);
                *posY -= 0.1 * sin(*angle);
                break;
            }
        }
    }
}

/**
 * main - Entry point of the program
 * 
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    int sdl_initialized = init_SDL(&window, &renderer);
    int quit = 0;
    float posX = SCREEN_WIDTH / 2.0;
    float posY = SCREEN_HEIGHT / 2.0;
    float angle = 0.0;

    if (sdl_initialized != 0)
    {
        printf("Failed to initialize SDL! (error code: %d)\n", sdl_initialized);
        return (1);
    }

    while (!quit)
    {
        handle_events(&quit, &posX, &posY, &angle);
        draw_walls(renderer, posX, posY, angle);
        SDL_Delay(16); /*Delay to control frame rate*/
    }

    close_SDL(window, renderer);

    return (0);
}
