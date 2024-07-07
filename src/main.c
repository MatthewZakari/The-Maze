#include "main.h"

/* The window and renderer */
SDL_Window *g_window = NULL;
SDL_Renderer *g_renderer = NULL;

/* The map and player */
int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

player_t player = {320, 240, 0};

/**
 * init - Initializes the SDL2 library, window, and renderer.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int init(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return (0);
    }

    g_window = SDL_CreateWindow("Maze Project",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return (0);
    }

    /* Use software rendering when using the dummy video driver */
    if (strcmp(SDL_GetCurrentVideoDriver(), "dummy") == 0)
    {
        g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_SOFTWARE);
    }
    else
    {
        g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
    }
    
    if (g_renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return (0);
    }

    return (1);
}

/**
 * close - Frees resources and closes SDL.
 */
void close(void)
{
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    g_renderer = NULL;
    SDL_Quit();
}

/**
 * render - Renders the game scene using raycasting.
 */
void render(void)
{
    int x;
    float ray_angle, ray_x, ray_y, ray_dir_x, ray_dir_y;
    int map_x, map_y;

    SDL_SetRenderDrawColor(g_renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(g_renderer);

    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        ray_angle = (player.angle - 30) + ((float)x / (float)SCREEN_WIDTH) * 60;
        ray_x = player.x;
        ray_y = player.y;
        ray_dir_x = cos(ray_angle * M_PI / 180.0);
        ray_dir_y = sin(ray_angle * M_PI / 180.0);

        while (1)
        {
            ray_x += ray_dir_x;
            ray_y += ray_dir_y;

            map_x = (int)(ray_x / TILE_SIZE);
            map_y = (int)(ray_y / TILE_SIZE);

            if (map[map_x][map_y] == 1)
            {
                SDL_SetRenderDrawColor(g_renderer, 0xFF, 0x00, 0x00, 0xFF);
                SDL_RenderDrawLine(g_renderer, player.x, player.y, ray_x, ray_y);
                break;
            }
        }
    }

    SDL_RenderPresent(g_renderer);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
    int quit = 0;
    SDL_Event e;

    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        while (!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = 1;
                }
            }
            render();
        }
    }

    close();
    return (0);
}

