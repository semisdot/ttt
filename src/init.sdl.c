// #include <stdio.h>

#include <SDL2/SDL.h>

#include "init.sdl.h"

#include "sdl.conf.h"

/* ---------------------------------------------------------------------------------------------------- */

static void error_SDL(const char *err_msg);

/* ---------------------------------------------------------------------------------------------------- */

void init_SDL(struct SDL *sdl)
{
	{
		if (SDL_Init(SDL_INIT_FLAGS) != 0)
		{
			error_SDL("SDL init");
		}

		atexit(SDL_Quit);
	}

	{
		sdl->window = SDL_CreateWindow(	SDL_WINDOW_TITLE,
										SDL_WINDOW_X,
										SDL_WINDOW_Y,
										SDL_WINDOW_WIDTH,
										SDL_WINDOW_HEIGHT,
										SDL_WINDOW_FLAGS);

		if (!sdl->window)
		{
			error_SDL("SDL window");
		}
	}

	// SDL_SetHint();

	{
		sdl->renderer = SDL_CreateRenderer( sdl->window,
											SDL_RENDERER_INDEX,
											SDL_RENDERER_FLAGS);

		if (!sdl->renderer)
		{
			error_SDL("SDL renderer");
		}
	}

	// SDL_SetRenderDrawBlendMode(sdl->renderer, SDL_BLENDMODE_BLEND);
}

/* ---------------------------------------------------------------------------------------------------- */

static void error_SDL(const char *err_msg)
{
	fprintf(stderr, "%s: %s\n", err_msg, SDL_GetError()); // log ?!

	exit(1);
}
