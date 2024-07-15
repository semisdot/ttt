#include <SDL2/SDL.h>

#include "init.sdl.h"
#include "init.game.h"

#include "stage.play.h"

#include "input.h"
#include "draw.h"

#include "app.struct.h"

/* ---------------------------------------------------------------------------------------------------- */

#define FPS			30 // ~
#define DELAY_TIME	(1000 / FPS)

/* ---------------------------------------------------------------------------------------------------- */

static void clear(struct SDL *sdl);
static void present(struct SDL *sdl);

/* ---------------------------------------------------------------------------------------------------- */

int main(void)
{
	struct application app;

	init_SDL(&app.sdl);
	init_game(&app.game);
	init_stage_play(&app);

	while (1) // main loop
	{
		clear(&app.sdl);

		input(&app.events);

		app.stage.logic(&app);

		draw(&app.sdl, &app.game);

		present(&app.sdl);

		SDL_Delay(DELAY_TIME);
	}

	return 0;
}

/* ---------------------------------------------------------------------------------------------------- */

static void clear(struct SDL *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(sdl->renderer);
}

static void present(struct SDL *sdl)
{
	SDL_RenderPresent(sdl->renderer);
}
