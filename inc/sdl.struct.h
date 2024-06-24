#ifndef SDL_STRUCT_H
#define SDL_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#include <SDL2/SDL.h>

/* ---------------------------------------------------------------------------------------------------- */

struct SDL
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
};

/* ---------------------------------------------------------------------------------------------------- */

#endif // SDL_STRUCT_H