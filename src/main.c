#include "maze.h"

/**
 * main - Entry point of the maze game
 * @argc: Argument count
 * @args: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *args[])
{
	(void)argc;
	(void)args;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (init_SDL(&window, &renderer) != 0)
	{
		printf("Failed to initialize SDL!\n");
		return (1);
	}

	draw_walls(renderer);

	SDL_Delay(5000);
	close_SDL(window, renderer);

	return (0);
}

