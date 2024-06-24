#include <SDL2/SDL.h>

#include "draw.h"

#include "game.conf.h"

/* ---------------------------------------------------------------------------------------------------- */

struct Line
{
	int x1, y1; // start points
	int x2, y2; // end points
};

// mySDL lib ?
static void mySDL_RenderDrawLine(SDL_Renderer *renderer, struct Line *line)
{
	SDL_RenderDrawLine(renderer, line->x1, line->y1, line->x2, line->y2);
}

static void mySDL_SetRenderDrawColor(SDL_Renderer *renderer, struct RGB_Color *rgb_color)
{
	SDL_SetRenderDrawColor(renderer, rgb_color->r, rgb_color->g, rgb_color->b, SDL_ALPHA_OPAQUE);
}

/* ---------------------------------------------------------------------------------------------------- */

static void draw_grid(struct SDL *sdl);
static void draw_players(struct SDL *sdl, struct Game *game);

/* ---------------------------------------------------------------------------------------------------- */

void draw(struct SDL *sdl, struct Game *game)
{
	draw_grid(sdl);
	draw_players(sdl, game);
}

/* ---------------------------------------------------------------------------------------------------- */

static void draw_grid(struct SDL *sdl)
{
	struct Line h_line; // horizontal line
	struct Line v_line; // vertical line
	int i;

	SDL_SetRenderDrawColor(sdl->renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);

	h_line.x1 = 0;
	h_line.x2 = GRID_WIDTH - 1;

	v_line.y1 = 0;
	v_line.y2 = GRID_HEIGHT - 1;

	for (i = 1; i < N; ++i)
	{
		h_line.y1 = h_line.y2 = CELL_HEIGHT * i;
		v_line.x1 = v_line.x2 = CELL_WIDTH * i;

		mySDL_RenderDrawLine(sdl->renderer, &h_line);
		mySDL_RenderDrawLine(sdl->renderer, &v_line);
	}
}

static void draw_players(struct SDL *sdl, struct Game *game)
{
	struct Player *player;
	int row, col;

	for (row = 0; row < GRID_ROWS; ++row)
	{
		for (col = 0; col < GRID_COLUMNS; ++col)
		{
			player = game->grid[row][col];

			if (player)
			{
				SDL_Rect rect;

				mySDL_SetRenderDrawColor(sdl->renderer, &player->rect_color);

				rect.x = col * CELL_WIDTH;
				rect.y = row * CELL_HEIGHT;
				rect.w = CELL_WIDTH;
				rect.h = CELL_HEIGHT;

				SDL_RenderFillRect(sdl->renderer, &rect);
			}
		}
	}
}
