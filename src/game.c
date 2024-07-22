#include <stddef.h> // NULL

#include "game.h"

/* ---------------------------------------------------------------------------------------------------- */

static int add_player_move(struct Game *game, int row, int col);

static int game_win(struct Game *game, int row, int col);
static int win_by_row(struct Game *game, int row, int col);
static int win_by_col(struct Game *game, int row, int col);
static int win_by_diagonal1(struct Game *game, int row, int col);
static int win_by_diagonal2(struct Game *game, int row, int col);

static int game_draw(struct Game *game);

/* ---------------------------------------------------------------------------------------------------- */

void game_move(struct Game *game, struct grid_position *pos, struct move_info *info)
{
	if (add_player_move(game, pos->row, pos->col))
	{
		info->move_status = PERFORMED;
	}
}

void game_status(struct Game *game, struct grid_position *pos, struct move_info *info)
{
	if (game_win(game, pos->row, pos->col))
	{
		info->game_status = WIN;
	}
	else if (game_draw(game))
	{
		info->game_status = DRAW;
	}
}

/* ---------------------------------------------------------------------------------------------------- */

static int add_player_move(struct Game *game, int row, int col)
{
	int ret = 0;

	if (game->grid.cells[row][col] == NULL)
	{
		game->grid.cells[row][col] = game->active_player;
		game->grid.rect_count += 1;

		ret = 1;
	}

	return ret;
}

static int game_win(struct Game *game, int row, int col)
{
	if (win_by_row(game, row, col)) return 1;
	if (win_by_col(game, row, col)) return 1;

	if (game->active_player == game->grid.cells[1][1]) // [(N - 1) / 2]
	{
		if (win_by_diagonal1(game, row, col)) return 1;
		if (win_by_diagonal2(game, row, col)) return 1;
	}

	return 0;
}

static int win_by_row(struct Game *game, int row, int col)
{
	int ret = 0;
	int col_in;
	int i;

	for (i = 1; i < N; ++i)
	{
		col_in = (col + i) % N;

		if (game->grid.cells[row][col_in] != game->active_player)
		{
			goto end;
		}
	}

	ret = 1;

end:
	return ret;
}

static int win_by_col(struct Game *game, int row, int col)
{
	int ret = 0;
	int row_in;
	int i;

	for (i = 1; i < N; ++i)
	{
		row_in = (row + i) % N;

		if (game->grid.cells[row_in][col] != game->active_player)
		{
			goto end;
		}
	}

	ret = 1;

end:
	return ret;
}

static int win_by_diagonal1(struct Game *game, int row, int col)
{
	int ret = 0;
	int row_in, col_in;
	int i;

	if (row != col) // (row - col != 0)
	{
		goto end;
	}

	for (i = 1; i < N; ++i)
	{
		row_in = (row + i) % N;
		col_in = (col + i) % N;

		if (game->grid.cells[row_in][col_in] != game->active_player)
		{
			goto end;
		}
	}

	ret = 1;

end:
	return ret;
}

static int win_by_diagonal2(struct Game *game, int row, int col)
{
	int ret = 0;
	int row_in, col_in;
	int i;

	if (row + col != N - 1)
	{
		goto end;
	}

	for (i = 1; i < N; ++i)
	{
		row_in = (row + i) % N;
		col_in = (N + (col - i)) % N;

		if (game->grid.cells[row_in][col_in] != game->active_player)
		{
			goto end;
		}
	}

	ret = 1;

end:
	return ret;
}

static int game_draw(struct Game *game)
{
	return (game->grid.rect_count == MAX_GRID_CELLS);
}
