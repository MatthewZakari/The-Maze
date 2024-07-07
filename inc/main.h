#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

/* Screen dimension constants */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* Map dimension constants */
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define TILE_SIZE 64

/**
 * struct player_s - Structure to represent the player.
 * @x: X coordinate of the player.
 * @y: Y coordinate of the player.
 * @angle: Viewing angle of the player.
 */
typedef struct player_s
{
    float x;
    float y;
    float angle;
} player_t;

int init(void);
void close(void);
void render(void);

extern SDL_Window *g_window;
extern SDL_Renderer *g_renderer;
extern int map[MAP_WIDTH][MAP_HEIGHT];
extern player_t player;

#endif /* MAIN_H */

